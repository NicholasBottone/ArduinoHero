#include <FastLED.h>
#include "Gameboard.h"

char data;
static int savedClock;
static bool start_button_pressed, up_button_pressed;


// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
  Serial.begin(9600);
  while (!Serial);
  
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
  // Print a message to the LCD.
  lcd.setCursor(1, 0);
  lcd.print("!!Welcome to!!");
  lcd.setCursor(0, 1);
  lcd.print("**Arduino Hero**");
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  //Move a single white led 
  moveLEDs();

  //update inputs
  if(digitalRead(START_BTN)) start_button_pressed = true;
  if(digitalRead(UP_BTN)) up_button_pressed = true;

  // GAME LOGIC: 
  static state CURRENT_STATE = sSONG_MENU;
  CURRENT_STATE = updateFSM(CURRENT_STATE, millis(), 
      start_button_pressed, up_button_pressed);
}



// Function that displays the starting screen of the game
void displayStart(){
}


// Function that displays the game at a given beat
void displayGame(beat b){

}

// Function that displays the end screen, which displays the player's max combo 
void displayEnd(combo_max){

}


// Function that dictates the game logic, state of the game!!!
state updateFSM(state currentState, long mils, bool startBtn, bool upBtn) {
  state nextState = curState;
  switch(curState) {
  
  case sSONG_MENU:
    if(!startBtn && !upBtn){ //transition 1-1a
      nextState = sSONG_MENU;
      displayStart_LCD(false, false);
    } 
    else if(!startBtn && upBtn){ //transition 1-1b (menu scroll)
      nextState = sSONG_MENU;
      displayStart_LCD(false, true);
      upBtn = false;
    }
    else if(startBtn){ //transition 1-2
      //on button press, send message to UNO to load song
      unsigned long currentMillis = millis();
      if((currentMillis - lastDebounceTime > debounceDelay) &&
          (digitalRead(buttonPin) == 1)){
        Serial1.write("L");
        Serial.println("load");
        lastDebounceTime = currentMillis;
      }

      //blocking function: waiting 
      while(!Serial1.available()){} //TODO - test if this is working

      //check that loaded message is received --> if loaded go to sCOUNTDOWN
      if (Serial1.available()){
        int inByte = Serial1.read();
        Serial.write(inByte);
        if(inByte == "received") nextState = sCOUNTDOWN;
      }

      displayStart_LCD(true, false);
      startBtn = false;
    } 
    break;
    
  case sCOUNTDOWN:
    if((mils - savedClock) >= 1000 && countdown >= 0){ //transition 2-2
      displayCoundown_LCD(countdown);
      countdown -= 1;
      savedClock = mils;
      nextState = sDISP_COUNTDOWN;
    } else if(countdown < 0){ //transition 2-3
      displayGame_LCD();
      savedClock = mils;
      nextState = sUPDATE_GAME;
    }
    break;

  case sUPDATE_GAME:
    //TODO
    if((mils - savedClock) < 10000) {
      moveLEDs();
      displayGame_LCD(combo_max, combo);
      nextState = sUPDATE_GAME;
    } else { //transition 3-4
      if(receiveFromUno() == "finished") {
        nextState = sGAME_OVER;
        savedClock = mils;
        displayEnd_LCD(combo_max);
      }
    }
    break;
  
  case sGAME_OVER:
    if((mils - savedClock) < 3000 || !gameButton) { // transition 4-4
      savedClock = mils;
      nextState = sGAME_OVER;
    }
    else if((mils - savedClock) >= 3000 && gameButton) { // transition 4-1
      savedClock = mils;
      countdown = 0;
      score = 0;
      gameButton = false;
      nextState = sSONG_MENU;
    }
    break;
  
  default:
    nextState = curState;
    break;

  return nextState;
}



// This function waits for then receives a message from the Uno, returning that 
// message as an int, a watchdog bites if this hangs (TODO)
int receiveFromUno(){
  while (Serial.available ()==0){}
  if(Serial1.available()>0){
    if(Serial1.read() == TODO-success message) {
      nextState = sCOUNTDOWN;
    }
  }
}