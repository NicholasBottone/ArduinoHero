// #include <LiquidCrystal.h>
#include "Gameboard.h"

// Number of Songs in the songs.h file
const int songName_len = sizeof(songList) / sizeof(songList[0]);


// Function that displays the starting screen of the game
void displayStart_LCD(bool startButtonPress, bool upButtonPress, bool firstCall){
  static int lastSongNum = -1; // Static variable to remember the last song number
  bool screenNeedsUpdate = false;

  // Check if it's the first call or if the track has changed
  if (firstCall || upButtonPress){
    song_num = (firstCall ? song_num : (song_num + 1) % songName_len);
    screenNeedsUpdate = (lastSongNum != song_num);
  }

  if (firstCall || startButtonPress || screenNeedsUpdate) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Track Selection:");

    lcd.setCursor(1, 1);
    lcd.print(song_num + 1);
    lcd.print(": ");
    lcd.setCursor(4, 1);
    lcd.print(songList[song_num].name);

    lastSongNum = song_num; // Update the last song number
  }

  if(startButtonPress){
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print(songList[song_num].name);

    curr_song = songList[song_num];
    beatmap = curr_song.beats;
    bpm_values = curr_song.bpm_values;
    bpm_change_indexes = curr_song.bpm_change_indexes;
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
  lcd.print("GAME OVER"); //TODO: Do the firstCall redraw as well

  lcd.setCursor(2, 2);
  lcd.print("max combo:");
  lcd.setCursor(13, 2);
  lcd.print(max_combo);
}