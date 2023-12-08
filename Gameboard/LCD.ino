// #include <LiquidCrystal.h>
#include "Gameboard.h"

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int songName_len = 3;
const char* songNames[songName_len] = {"Song 1", "Song 2", "Song 3"};
int song_num = 0;


// Function that displays the starting screen of the game
void displayStart_LCD(bool startButtonPress, bool upButtonPress){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Track Selection:");

  lcd.setCursor(5, 1);
  lcd.print(songNames[song_num]);

  if(upButtonPress){
    lcd.setCursor(5, 1);
    song_num = (song_num+1) % (songName_len) ;
    Serial.println(song_num);
    lcd.print(songNames[song_num]);
  }

  if(startButtonPress){
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print(songNames[song_num]);
  }
}


// Function that displays the countdown screen
void displayCoundown_LCD(int countdown){
  //start a count down
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print(countdown);

  //end of countdown
  if(countdown == 0){
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Countdown Done!");
  }
}


// Function that displays the LCD screen during gameplay.
// shows current combo and max combo
void displayGame_LCD(int max_combo, int curr_combo){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Combo:");

  lcd.setCursor(7, 0);
  lcd.print(curr_combo);
}


// Function that displays the end screen, which displays the player's max combo 
void displayEnd_LCD(int max_combo){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAME OVER"); //TODO

  lcd.setCursor(2, 2);
  lcd.print("max combo:");
  lcd.setCursor(13, 2);
  lcd.print(max_combo);
}