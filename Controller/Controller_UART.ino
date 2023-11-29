/*
 * Manually wait for UART cycle
 */
inline void uartDelay(unsigned long ltime) {
  delayMicroseconds(UART_PERIOD_MICROS - (micros() - ltime));
}

/*
 * Send byte via UART (only populating 7 bits)
 */
void uartSend(byte B) {  
  digitalWrite(outPin, LOW);
  unsigned long lastClockTime = micros(); // record when pin was flipped
  
  int i = 0;
  byte parity = 0;
  while (i < 7) {
    
    if ((B & 0x1) == 0x1 ) {
      uartDelay(lastClockTime);
      digitalWrite(outPin, HIGH);
      lastClockTime = micros();
      parity = parity ^ 0x01;
    } else {
      uartDelay(lastClockTime);
      digitalWrite(outPin, LOW);
      lastClockTime = micros();
    }
    B = B >> 1;
    i += 1;
  }
  uartDelay(lastClockTime);

  // write parity bit;
  if (parity == 1) {
    digitalWrite(outPin, HIGH);
  } else {
    digitalWrite(outPin, LOW);
  }
  uartDelay(micros());
  digitalWrite(outPin, HIGH);
}


 /*
  * Read a byte from the UART
  * (not needed for current implementation)
  */
void uartReceive() {
}



