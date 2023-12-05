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
  if(Serial1.available()){
    int inByte = Serial1.read();
    Serial.print("inByte: ");
    Serial.println(inByte);

    //patrick's logic to edit scores goes here!
  }
}