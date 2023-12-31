

// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

#include <SoftwareSerial.h>
const byte rxPin = 2;
const byte txPin = 3;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);
// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

// To play the song, send the 

Adafruit_VS1053_FilePlayer musicPlayer = 
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);
  
void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Adafruit VS1053 Simple Test");

  if (!musicPlayer.begin()) { // initialise the music player
        Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
        while (1);
  }
  Serial.println(F("VS1053 found"));
  if (!SD.begin(CARDCS)) {
      Serial.println(F("SD failed, or not present"));
      while (1);  // don't do anything more
  }

  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(20,20);
  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
  mySerial.begin(9600);

}

void loop() {
  //receiving from MKR and printing loop if there is a byte to read
  if(mySerial.available()) {
    char inByte = (mySerial.read());
    //stops and ends song    
    if(inByte == 'S'){
      // mySerial.write("S\n");
      // Serial.write("Stop");
      musicPlayer.stopPlaying();
    }

    //starts songs from beginning
    if(inByte == '1'){
      delay(3280);
      //Currently Boulevard
      musicPlayer.startPlayingFile("/track001.mp3");
    }

    if(inByte == '2'){
      delay(1400);
      //currently Deja Vu
      musicPlayer.startPlayingFile("/track002.ogg");
    }

    if(inByte == '3'){
      //Currently Shake It Off
      delay(100);
      musicPlayer.startPlayingFile("/track003.ogg");
    }

    if(inByte == '4'){
      delay(850);
      //Currently Harder Better Faster
      musicPlayer.startPlayingFile("/track004.mp3");
    }

    if(inByte == '5'){
      delay(1150);
      //Currently All I Want For Christmas Is You
      musicPlayer.startPlayingFile("/track005.mp3");
    }

  }

  // delay(100);
}
