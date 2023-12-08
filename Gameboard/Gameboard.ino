#include <FastLED.h>
#include "Gameboard.h"

char data;
static int savedClock;
static bool start_button_pressed, up_button_pressed;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
  Serial.begin(115200);   // initialise serial monitor port
  while (!Serial) {}
  Serial1.begin(9600);  // initialise Serial1

  pinMode(START_BTN, INPUT);
  pinMode(UP_BTN, INPUT);
  pinMode(UART_IN_PIN, INPUT);
  attachInterrupt(UART_IN_PIN, uartReceive, CHANGE);

  savedClock = 0;
  start_button_pressed = false;
  up_button_pressed = false;

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  //RGB ordering is typical

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
  updateInputs();
  static state CURRENT_STATE = sSONG_MENU;
  CURRENT_STATE = updateFSM(CURRENT_STATE, millis(), 
      start_button_pressed, up_button_pressed);

  start_button_pressed = false;
  up_button_pressed = false;
}

void updateInputs(){
  unsigned long currentMillisDebounce = millis();
  if((currentMillisDebounce - lastDebounceTime > debounceDelay) &&
      digitalRead(START_BTN)){
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
  state nextState = curState;
  switch(curState) {
  
  case sSONG_MENU:
    if(!startBtn && !upBtn){ //transition 1-1a
      nextState = sSONG_MENU;
      displayStart_LCD(false, false);
    } 
    else if(!startBtn && upBtn){ //transition 1-1b (menu scroll)
      nextState = sSONG_MENU;

      Serial1.write("S");

      //blocking function: waiting 
      // while(!Serial1.available()){} //TODO - test if this is working

      displayStart_LCD(false, true);
    }
    else if(startBtn && !upBtn){ //transition 1-2
      //on button press, send message to UNO to load song
      unsigned long currentMillis = millis();

      Serial1.write("L");

      //blocking function: waiting 
      // while(!Serial1.available()){} //TODO - test if this is working

      //check that loaded message is received --> if loaded go to sCOUNTDOWN
      if (Serial1.available()){
        int inByte = Serial1.read();
        Serial.write(inByte);
        if(inByte == (int)"received") nextState = sCOUNTDOWN;
      }

      displayStart_LCD(true, false);
      nextState = sCOUNTDOWN;
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
    //TODO -- ALL WORK LEFT IS IN HERE
    if((mils - savedClock) < 10000) {
      moveLEDs();
      displayGame_LCD(combo_max, combo);
      nextState = sUPDATE_GAME;
      beat_index += 1;
    } else if(beatmap[beat_index] == 0b11111111) { //transition 3-4
      nextState = sGAME_OVER;
      savedClock = mils;
      clearLEDs();
    }
    break;
  
  case sGAME_OVER:
    displayEnd_LCD(combo_max);
    if((mils - savedClock) < 3000 || !start_button_pressed) { // transition 4-4
      savedClock = mils;
      nextState = sGAME_OVER;
    } else if((mils - savedClock) >= 3000 && start_button_pressed) { // transition 4-1
      savedClock = mils;
      countdown = 0;
      score = 0;
      start_button_pressed = false;
      nextState = sSONG_MENU;
    }
    break;
  
  default:
    nextState = curState;
    break;
  }

  return nextState;
}


// This function waits for then receives a message from the Uno, returning that 
// message as an int, a watchdog bites if this hangs (TODO)
int receiveFromUno(){
  if(Serial1.available()>0){
    return (int)Serial1.read();
  }
  return -1;
}
