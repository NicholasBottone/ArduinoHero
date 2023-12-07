/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 https://docs.arduino.cc/learn/electronics/lcd-displays

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 0, e = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
const int START_BTN = 6;
const int UP_BTN = 7;
const int songName_len = 3;
const char* songNames[songName_len] = {"Song 1", "Song 2", "Song 3"};


bool isStartGame = false;
bool isSongMenu = true;

int countdown_num = 3;
int song_num = 0;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(1, 0);
  lcd.print("!!Welcome to!!");
  lcd.setCursor(0, 1);
  lcd.print("**Arduino Hero**");

  isSongMenu = true;
  delay(1000);

  Serial.begin(9600);
  while (!Serial); // Wait for Serial to initialize
  pinMode(START_BTN, INPUT);
  pinMode(UP_BTN, INPUT);

  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  // lcd.print(millis() / 1000);
  // Serial.println(digitalRead(START_BTN));
  // Serial.println(digitalRead(UP_PIN));
  if(isSongMenu){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Track Selection:");

    lcd.setCursor(5, 1);
    lcd.print(songNames[song_num]);

    if(digitalRead(UP_BTN)){
      lcd.setCursor(5, 1);
      song_num = (song_num+1) % (songName_len) ;
      Serial.println(song_num);
      lcd.print(songNames[song_num]);
      delay(500);
    }

    if(digitalRead(START_BTN)){
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print(songNames[song_num]);
      isStartGame = true;
      isSongMenu = false;
      delay(1000);
    }

  }

  if(isStartGame && !isSongMenu){
    //start a count down
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print(countdown_num);
    delay(1000);
    countdown_num--;
    if(countdown_num == 0){
      isStartGame = false;
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Countdown Done!");
    }
  }

}