#include "Gameboard.h"

//file with all communication functions with other microcontrollers

const int UART_PERIOD_MICROS = 104;


 /*
  * Read a byte from the UART
  * form: 0 bit, then 7 bits of information, corresponding: in order from L to R
  *  0. 0 
  *  1. Strum up
  *  2. Strump down
  *  3. Red Button
  *  4. Blue Button
  *  5. Green Button
  *  6. Yellow Button
  *  7. Purple Button
  */
void uartReceive() {
  // delay for 1/3 of the UART period just to get reads towards the middle of bits
  delayMicroseconds(UART_PERIOD_MICROS / 3);
  unsigned long lastClockTime = micros();
  int i = 0;
  byte B = 0;
  byte parity = 0;
  while (i < 7) {
    B = B >> 1;
    uartDelay(lastClockTime);
    int inPinVal = digitalRead(UART_IN_PIN);
    lastClockTime = micros();
    if (inPinVal == HIGH) {
      B = B | (0x1 << 6);
      parity = parity ^ 0x01;
    }
    i += 1;
  }
  // Receive parity bit
  uartDelay(lastClockTime);
  int inPinVal = digitalRead(UART_IN_PIN);
  lastClockTime = micros();
  // compare computed and received parity
  // if match, use value
  if(parity == inPinVal){
    //GAME LOGIC HERE
    // Serial.println("COMBO CHECK");
    // Serial.print("beat: ");
    // Serial.print(beatmap[beat_index], BIN);
    // Serial.print(" vs input:");
    // Serial.println(B, BIN);
    //   Serial.print(" (");
    // Serial.print(B & 0b00011111);
    // Serial.print(") ");
    // TODO: Track last beat_index  that we got points at to prevent double points
    if((beatmap[beat_index-4] & 0b00011111) == (B & 0b00011111) ||
      (beatmap[beat_index-5] & 0b00011111) == (B & 0b00011111) ||
      (beatmap[beat_index-6] & 0b00011111) == (B & 0b00011111)){
      score += 1;
      Serial.print("score: ");
      Serial.println(score);
      combo += 1;
      if(combo > combo_max) combo_max = combo;
      Serial.print("current combo: ");
      Serial.print(combo);
      Serial.print(" (max: ");
      Serial.print(combo_max);
      Serial.println(")");
    } else {
      if(combo > combo_max) combo_max = combo;
      combo = 0;
    }
  }
  
}

/*
 * Manually wait for UART cycle
 */
inline void uartDelay(unsigned long ltime) {
  delayMicroseconds(UART_PERIOD_MICROS - (micros() - ltime));
}
