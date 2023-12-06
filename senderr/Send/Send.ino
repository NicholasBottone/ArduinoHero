// Arduino MKRFOX hardware serial1 test

// NOTE: MKRFOX uses 3.3V logic 
// - if commected to UNO 5V logic use a voltage divider 2.2K to ground 1K to UNO Tx

// MKRFOX pin 14 is TX
// MKRFOX pin 13 is Rx

// for loopback test connect pin 13 to pin 14
const int buttonPin = 7;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

void setup() {
  Serial.begin(115200);   // initialise serial monitor port
  while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }  
  Serial1.begin(9600);  // initialise Serial1
  Serial.println();
  pinMode(buttonPin, INPUT);
}

void loop() {
  //receive from UNO
  if (Serial1.available()){
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  //send to UNO on button press
  unsigned long currentMillis = millis();
  if((currentMillis - lastDebounceTime > debounceDelay) &&
      (digitalRead(buttonPin) == 1)){
    Serial1.write("L");
    Serial.println("load");
    lastDebounceTime = currentMillis;
  }
}

