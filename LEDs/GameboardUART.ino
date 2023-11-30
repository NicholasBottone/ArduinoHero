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
  * form: 7 bits, corresponding: in order from left to right
  *  1. 
  */
void uartReceive() {
}



