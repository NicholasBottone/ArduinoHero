#include "Controller.h"

// #define CALIBRATE // used for checking hardware

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  while (!Serial); // Wait for Serial to initialize

  pinMode(outPin, OUTPUT);

  pinMode(GREEN_BUTTON, INPUT);
  pinMode(RED_BUTTON, INPUT);
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  pinMode(ORANGE_BUTTON, INPUT);
  
  pinMode(STRUM_BUTTON_UP, INPUT);
  pinMode(STRUM_BUTTON_DOWN, INPUT);

  attachInterrupt(STRUM_BUTTON_UP, strumUpInterrupt, RISING);
  attachInterrupt(STRUM_BUTTON_DOWN, strumDownInterrupt, RISING);
}

void loop() {}

// interrupt handler for strum up.
void strumUpInterrupt(){
  byte B = 0;
  B |= (1 << 6);
  handleInterrupt(B);
}

// interrupt handler for strum down.
void strumDownInterrupt() {
  byte B = 0;
  B |= (1 << 5);
  handleInterrupt(B);
}

/**

*/
void handleInterrupt(byte B) {
  unsigned long currentMillis = millis();
  if (currentMillis - lastDebounceTime > debounceDelay) {
    #if defined(CALIBRATE)
      hardwareCheck();

    #else
      noInterrupts();
      /*create byte to represent the user event,
      with each bit corresponding to a button 
      press (1 being pressed) */
      for(int i = 6; i < 11; i++){
        // Serial.println((int)B, BIN);
        if(digitalRead(i) == 1) {
          B |= (1 << (i-6));
        }
      }
      uartSend(B);
      lastDebounceTime = currentMillis;
      interrupts();
  }
  #endif
}

//a function to check if the buttons are wired correctly in the controller circuit
void hardwareCheck(){
  if(digitalRead(GREEN_BUTTON) == 1) {
    Serial.print("G");

  } else {
    Serial.print("- ");
  }

  if(digitalRead(RED_BUTTON) == 1) {
    Serial.print("R");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(YELLOW_BUTTON) == 1){
    Serial.print("Y");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(BLUE_BUTTON) == 1) {
    Serial.print("B");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(ORANGE_BUTTON) == 1) {
    Serial.println("O");
  } else {
    Serial.println("-");
  }
}