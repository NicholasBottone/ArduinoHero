#include <FastLED.h>
#include "Gameboard.h"

// #define CHECK_UNO_COMMUNICATION

char data;
static int savedClock, finish_count;
static bool start_button_pressed, up_button_pressed;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

// This function sets up the ledsand tells the controller about them
void setup() {
  Serial.print("a");
  Serial.begin(115200);   // initialise serial monitor port
  Serial.print("b");
  while (!Serial) {}
  Serial1.begin(9600);  // initialise Serial1

  pinMode(START_BTN, INPUT);
  pinMode(UP_BTN, INPUT);
  pinMode(UART_IN_PIN, INPUT);
  attachInterrupt(UART_IN_PIN, uartReceive, CHANGE);

  savedClock = 0;
  start_button_pressed = false;
  up_button_pressed = false;
  finish_count = 6;

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("!!Welcome to!!");
  lcd.setCursor(0, 1);
  lcd.print("**Arduino Hero**");

  Serial.println("setup complete");
  delay(1500);
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {

  #ifdef CHECK_UNO_COMMUNICATION
    checkUnoCommunication();
    if(Serial1.available()) {
      Serial.print("receive: ");
      Serial.write(Serial1.read());
      Serial.println();
    }
    
  #else

  updateInputs();
  static state CURRENT_STATE = sSONG_MENU;
  CURRENT_STATE = updateFSM(CURRENT_STATE, millis(), 
      start_button_pressed, up_button_pressed);

  start_button_pressed = false;
  up_button_pressed = false;

  #endif
}

void updateInputs(){
  unsigned long currentMillisDebounce = millis();
  if((currentMillisDebounce - lastDebounceTime > debounceDelay) &&
      digitalRead(START_BTN)){
    Serial.println("start pressed");
    start_button_pressed = true;
    lastDebounceTime = currentMillisDebounce;
  }
  if((currentMillisDebounce - lastDebounceTime > debounceDelay) &&
      digitalRead(UP_BTN)){
    up_button_pressed = true;
    lastDebounceTime = currentMillisDebounce;
  }
}


// Function that dictates the game logic, state of the game!!!
state updateFSM(state curState, long mils, bool startBtn, bool upBtn) {
  static bool isFirstCall = true; // Static variable to remember if it's the first call in the current state
  state nextState = curState;
  switch(curState) {
  
  case sSONG_MENU:
    if(isFirstCall || !startBtn && !upBtn){ //transition 1-1a
      nextState = sSONG_MENU;
      displayStart_LCD(false, false, isFirstCall);
      isFirstCall = false;
    } 
    else if(!startBtn && upBtn){ //transition 1-1b (menu scroll)
      nextState = sSONG_MENU;

      Serial1.write(song_num);

      displayStart_LCD(false, true, false);
    }
    else if(startBtn && !upBtn){ //transition 1-2
      //on button press, send message to UNO to load song
      unsigned long currentMillis = millis();

      Serial1.write("1");
      Serial.println("starting");

      //blocking function: waiting 
      // while(!Serial1.available()){} //TODO - test if this is working

      //check that loaded message is received --> if loaded go to sCOUNTDOWN
      // if (Serial1.available()){
      //   int inByte = Serial1.read();
      //   Serial.write(inByte);
      //   if(inByte == (int)"received") nextState = sCOUNTDOWN;
      // }

      displayStart_LCD(true, false, false);
      nextState = sCOUNTDOWN;
      isFirstCall = true; // Reset for next time entering this state
    } 
    break;
    
  case sCOUNTDOWN:
    if((mils - savedClock) >= 1000 && countdown >= 0){ //transition 2-2
      displayCoundown_LCD(countdown);
      countdown -= 1;
      savedClock = mils;
      nextState = sCOUNTDOWN;
    } else if(countdown < 0){ //transition 2-3
      displayGame_LCD(combo_max, combo);
      savedClock = mils;
      nextState = sUPDATE_GAME;
    }
    break;


  case sUPDATE_GAME:
    if(millis() >= nextUpdateTime){
      unsigned long start_beat_millis = millis(); 
      // Serial.print("beat: ");
      // Serial.print(beat_index);
      // Serial.print("/");
      // Serial.println(curr_song.beats_length);
      if(beatmap[beat_index] != 0b11111111 && beat_index < curr_song.beats_length){ //transition 3-3(a)
        moveLEDs(false);
        displayGame_LCD(combo_max, combo);
        nextState = sUPDATE_GAME;
        beat_index += 1;
        savedClock = millis();
        performTimeStepDelay(start_beat_millis);
        // clearLEDs();
      } else if(((beatmap[beat_index] == 0b11111111) || beat_index >= curr_song.beats_length)  // stop note || no more beats 
          && finish_count >= 0) { //transition 3-3(b)
        finish_count -= 1;
        performTimeStepDelay(start_beat_millis);
        moveLEDs(true);
        displayGame_LCD(combo_max, combo);
        nextState = sUPDATE_GAME;
      } else if(finish_count < 0){ //transition 3-4
        performTimeStepDelay(start_beat_millis);
        // clearLEDs();
        nextState = sGAME_OVER;
        savedClock = mils;
        finish_count = 6;
      }
    }
    break;
  
  case sGAME_OVER:
    displayEnd_LCD(combo_max);
    if((mils - savedClock) < 3000 || !start_button_pressed) { // transition 4-4
      nextState = sGAME_OVER;
    } else if((mils - savedClock) >= 3000 && start_button_pressed) { // transition 4-1
      savedClock = mils;
      countdown = 3; // reset countdown for next track selection
      score = 0;
      combo = 0;
      combo_max = 0;
      start_button_pressed = false;
      nextState = sSONG_MENU;
      beat_index = START_BEAT_INDEX;
    }
    break;
  
  default:
    nextState = curState;
    break;
  }

  return nextState;
}


void checkUnoCommunication(){
  unsigned long currentMillisDebounce = millis();
  if((currentMillisDebounce - lastDebounceTime > debounceDelay) &&
    digitalRead(START_BTN)){
    Serial1.write("1");
    Serial.println("send: 1");
    lastDebounceTime = currentMillisDebounce;
  }
  if((currentMillisDebounce - lastDebounceTime > debounceDelay) &&
    digitalRead(UP_BTN)){
    Serial1.write("S");
    Serial.print("send: S");
    song_num += 1;
    lastDebounceTime = currentMillisDebounce;
  }
}
