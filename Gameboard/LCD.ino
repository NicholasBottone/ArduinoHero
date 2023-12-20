#include "Gameboard.h"

// Number of Songs in the songs.h file
const int songName_len = sizeof(songList) / sizeof(songList[0]);


// Function that displays the starting screen of the game
int displayStart_LCD(bool startButtonPress, bool upButtonPress, bool firstCall){
  #ifndef TESTING
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

  return song_num;
  #else
  outputFunctionsCalled += "displayStart_LCD(" + String(startButtonPress) + ", " + String(upButtonPress) + ", " + String(firstCall) + ")\n";
  #endif
}



// Function that displays the countdown screen
void displayCountdown_LCD(int countdown){
  #ifndef TESTING
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
  #else
  outputFunctionsCalled += "displayCountdown_LCD(" + String(countdown) + ")\n";
  #endif
}


// Function that displays the LCD screen during gameplay.
// shows current combo and max combo
void displayGame_LCD(int max_combo, int curr_combo){
  #ifndef TESTING
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Score:");

  lcd.setCursor(7, 0);
  lcd.print(score);

  lcd.setCursor(0, 1);
  lcd.print("Combo:");

  lcd.setCursor(7, 1);
  lcd.print(curr_combo);
  #else
  outputFunctionsCalled += "displayGame_LCD(" + String(max_combo) + ", " + String(curr_combo) + ")\n";
  #endif
}


// Function that displays the end screen, which displays the player's max combo 
void displayEnd_LCD(int max_combo, bool startButtonPress, bool firstCall){
  #ifndef TESTING
  static bool lastStateStartButtonPress = false; // Remember the last button press state

  // Determine if the screen needs an update
  bool screenNeedsUpdate = firstCall || (startButtonPress != lastStateStartButtonPress);

  // Update the screen based on the conditions
  if (screenNeedsUpdate) {
    lcd.clear();
    if (!startButtonPress) {
      // Display the game over screen
      lcd.setCursor(3, 0);
      lcd.print("GAME OVER");

      // Display score and max combo on the same line
      lcd.setCursor(0, 1); // Set cursor to start of second row
      lcd.print("Sc:");
      lcd.print(score);
      lcd.print(" Cm:");
      lcd.print(max_combo);

      Serial.print("score: ");
      Serial.println(score);
      Serial.print("max combo: ");
      Serial.println(max_combo);
    } else {
      // Additional display logic when start button is pressed
      lcd.setCursor(0, 0);
      lcd.print("Start button pressed");
    }

    lastStateStartButtonPress = startButtonPress; // Update the last button press state
  }
  #else
  outputFunctionsCalled += "displayEnd_LCD(" + String(max_combo) + ", " + String(startButtonPress) + ", " + String(firstCall) + ")\n";
  #endif
}
