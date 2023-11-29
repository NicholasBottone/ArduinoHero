#include "Controller.h"

// #define CALIBRATE;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to initialize
  pinMode(RED_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(PURPLE_BUTTON, INPUT);
  pinMode(STRUM_BUTTON_UP, INPUT);
  pinMode(STRUM_BUTTON_DOWN, INPUT);

  attachInterrupt(STRUM_BUTTON_UP, strumInterrupt, RISING);
  attachInterrupt(STRUM_BUTTON_DOWN, strumInterrupt, RISING);
}

void loop() {
}

void strumInterrupt() {

  #if defined(CALIBRATE)
    hardwareCheck();
  
  #else
    noInterrupts();
    /*create byte to represent the user event,
    with each bit corresponding to a button 
    press (1 being pressed) */
    byte B = 0;
    for(int i = 4; i < 11; i++){
      if(digitalRead(i) == 1) {
        B |= (1 << (i-4));
      }
    }

    uartSend(B);
    interrupts();
  #endif
  
  // delay(100);
}

//a function to check if the buttons are wired correctly in the controller circuit
void hardwareCheck(){
  if(digitalRead(RED_BUTTON) == 1) {
    Serial.print("R ");

  } else {
    Serial.print("- ");
  }

  if(digitalRead(PURPLE_BUTTON) == 1) {
    Serial.print("P ");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(GREEN_BUTTON) == 1){
    Serial.print("G ");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(YELLOW_BUTTON) == 1) {
    Serial.print("Y ");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(BLUE_BUTTON) == 1) {
    Serial.println("B");
  } else {
    Serial.println("-");
  }
}
