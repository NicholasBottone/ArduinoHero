//file with all communication functions with other microcontrollers

 /*
  * Read a byte from the UART
  * form: 7 bits of information, corresponding: in order from left to right
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
    }
    // get past this last bit so as not to trigger an early interrupt
  uartDelay(lastClockTime);
}

/*
 * Manually wait for UART cycle
 */
inline void uartDelay(unsigned long ltime) {
  delayMicroseconds(UART_PERIOD_MICROS - (micros() - ltime));
}
