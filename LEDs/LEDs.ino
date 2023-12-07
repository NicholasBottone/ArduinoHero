#include <FastLED.h>
#include "Gameboard.h"

char data;
static int savedClock, countdown;


// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
  Serial.begin(9600);
  Serial1.
  while (!Serial);
  
  pinMode(UART_IN_PIN, INPUT);
  attachInterrupt(UART_IN_PIN, uartReceive, CHANGE);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // RGB ordering is typical

  savedClock = 0;
  countdown = 3;
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
  //Move a single white led 
  moveLEDs();
  // updateFSM();
  static state CURRENT_STATE = sSONG_MENU;
  updateInputs();
  CURRENT_STATE = updateFSM(CURRENT_STATE, millis(), numButtonsPressed, lastButtonPressed);
  delay(10);
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
state updateFSM(state currentState, long mils, int numButtons, int lastButton) {
  state nextState = curState;
  switch(curState) {
  
  case sSONG_MENU:
    if(gameButton){ //transition 1-2
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

      // if((int)"received" == receiveFromUno()) nextState = sCOUNTDOWN;
    }
    break;
    
  case sCOUNTDOWN:
    if((mils - savedClock) >= 1000 && countdown >= 0){ //transition 2-2
      countdown -= 1;
      savedClock = mils;
      nextState = sDISP_COUNTDOWN;
    } else if(countdown < 0){ //transition 2-3
      savedClock = mils;
      nextState = sUPDATE_GAME;
    }
    break;

  case sUPDATE_GAME:
    //TODO
    if((mils - savedClock) < 10000) {
      moveLEDs();
      nextState = sGame;
    } else { //transition 3-4
      if(receiveFromUno() == "finished") {
        nextState = sGAME_OVER;
        savedClock = mils;
      }
    }
    break;
  
  case sGAME_OVER:
    if((mils - savedClock) >= 3000 && gameButton) { // transition 4-1
      savedClock = mils;
      countdown = 0;
      score = 0;
      nextState = sSONG_MENU;
    }
    break;
  
  default:
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


// This function moves the LEDs Down the LED display
void moveLEDs() {
  for(int i = 0; i < LEDS_PER_COLUMN; i++) {
    // Turn our current led on to white, then show the leds
    leds[getLEDIndex(ORANGE, i)] = CRGB::OrangeRed;
    leds[getLEDIndex(YELLOW, i)] = CRGB::Yellow;
    leds[getLEDIndex(BLUE, i)] = CRGB::Blue;
    leds[getLEDIndex(RED, i)] = CRGB::Red;
    leds[getLEDIndex(GREEN, i)] = CRGB::Green;

    // Show the leds (only one of which is set to white, from above)
    FastLED.show();

    // Wait a little bit
    delay(400);

    // Turn our current led back to black for the next loop around
    leds[getLEDIndex(ORANGE, i)] = CRGB::Black;
    leds[getLEDIndex(YELLOW, i)] = CRGB::Black;
    leds[getLEDIndex(BLUE, i)] = CRGB::Black;
    leds[getLEDIndex(RED, i)] = CRGB::Black;
    leds[getLEDIndex(GREEN, i)] = CRGB::Black;
  }
}

//TODO -- need documentation of this function
int getLEDIndex(ColorColumn color_column, int index) {
  int row = color_column % 2 == 0 ? index : (LEDS_PER_COLUMN - 1 - index);
  return (color_column * LEDS_PER_COLUMN) + row;
}
