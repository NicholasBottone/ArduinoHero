/*
 * Manually wait for UART cycle
 */
inline void uartDelay(unsigned long ltime) {
  delayMicroseconds(UART_PERIOD_MICROS - (micros() - ltime));
}

/*
 * Send byte via UART
 * (not needed for current implementation)
 */
void uartSend(byte B) { 
}


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
    int inPinVal = digitalRead(inPin);
    lastClockTime = micros();
    if (inPinVal == HIGH) {
      B = B | (0x1 << 6);
      parity = parity ^ 0x01;
    }
    i += 1;
  }
  // Receive parity bit
  uartDelay(lastClockTime);
  int inPinVal = digitalRead(inPin);
  lastClockTime = micros();
  // compare computed and received parity
  // if match, use value
   if(parity == inPinVal){
    if(rBufStart != (rBufEnd + 1) % rsBufSize){ 
      /*NOTE: 7 bits are being put into the buffer, to 
      check note values, only the last 5 bits are needed! */
      rBufEnd = (rBufEnd + 1) % rsBufSize;
      rBuf[rBufEnd] = B;
    }
  }

  // get past this last bit so as not to trigger an early interrupt
  uartDelay(lastClockTime);
}