/* Software serial multple serial test

 on the UNO circuit is:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

// Note: UNO uses 5V logic 
//   - if connecting the 3.3V logic use a voltage divider 2.2K to ground 1K to UNO Tx

 Note uses interrupts on pin:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 */
#include <SoftwareSerial.h>

#define SOFTWARE_TEST

const byte rxPin = 2;
const byte txPin = 3;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  #if defined(SOFTWARE_TEST)
    Serial.println();
    Serial.println("SoftwareSerial test");
  #endif

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

void loop() { // run over and over

  //receiving from MKR and printing loop
  if(mySerial.available()) {
    Serial.write(mySerial.read());
    mySerial.write("received\n");
  }
}

