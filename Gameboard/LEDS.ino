#include <FastLED.h>
#include "Gameboard.h"

bool beat_queue[6][5];

// Create a 2D array to represent the 5 columns and their respective LED colors
CRGB columnColors[5][LEDS_PER_COLUMN];

float cumulativeDrift = 0.0; // To track the drift over time during the loop

// unsigned int queue_index = 0;

void performTimeStepDelay(unsigned long start_beat_millis){
    // Get the current BPM
    float current_bpm = curr_song.bpm_values[bpm_index];

    // Calculate the delay for the current BPM
    float calculatedDelay = 60000.0 / current_bpm / curr_song.sampling_rate;

    // Calculate and compensate for drift
    int actualDelay = (int)calculatedDelay;
    cumulativeDrift += (calculatedDelay - actualDelay);
    if (cumulativeDrift >= 1.0) {
        actualDelay += 1;
        cumulativeDrift -= 1.0;
    }

    // Schedule the next update time
    nextUpdateTime = start_beat_millis + actualDelay;

    // Check for BPM change for the next beat
    if (bpm_index < curr_song.bpm_values_length - 1 &&
        beat_index - 5 == curr_song.bpm_change_indexes[bpm_index + 1]) {
        Serial.print("BPM changing at beat ");
        Serial.print(beat_index);
        Serial.print(" from ");
        Serial.print(curr_song.bpm_values[bpm_index]);
        Serial.print(" to ");
        bpm_index++; // Move to the next BPM value for the next beat
        Serial.println(curr_song.bpm_values[bpm_index]);
    }
}


// void performTimeStepDelay(unsigned long start_beat_millis){
//   /* Based on the current tempo, resolution, previous drift, etc... determine the appropriate amount of delay to stay on time w/ the music*/

//   // Check for BPM change at the current beat
//   if (bpm_index < curr_song.bpm_values_length - 1 &&
//       beat_index == curr_song.bpm_change_indexes[bpm_index + 1]) {
//       Serial.print("BPM changing at beat ");
//       Serial.print(beat_index);
//       Serial.print(" from ");
//       Serial.print(curr_song.bpm_values[bpm_index]);
//       Serial.print(" to ");
//       bpm_index++; // Update to the next BPM value
//       Serial.println(curr_song.bpm_values[bpm_index]);
//   }

//   // Get the current BPM
//   float current_bpm = curr_song.bpm_values[bpm_index];
//   // Serial.print("Current BPM: ");
//   // Serial.println(current_bpm);

//   // Calculate the delay for the current BPM
//   float calculatedDelay = 60000.0 / current_bpm;

//   // Adjust the delay based on the sampling_rate we sampled at. If we sampled at sampling_rate=1, then we did every quarter note. 
//   // If sampling_rate=2, we sampled every eight note and our minimum tick speed has to progress at 8th note speed (twice the bpm)
//   calculatedDelay = calculatedDelay / curr_song.sampling_rate;

  
//   // Calculate drift
//   int actualDelay = (int)calculatedDelay;
//   cumulativeDrift += (calculatedDelay - actualDelay);

//   // Compensate for drift
//   if (cumulativeDrift >= 1.0) {
//       actualDelay += 1;
//       cumulativeDrift -= 1.0;
//   }

//   // Serial.print("Cumulative drift: ");
//   // Serial.println(cumulativeDrift);

//   // Delay for the adjusted time
//   // delay(actualDelay); // DELAY IS NO NO, BAD DRIFT

  
//   // Serial.print("actualDelay: ");
//   // Serial.println(actualDelay);

//   // Schedule the next update time
//   nextUpdateTime = start_beat_millis + actualDelay;
// }





void moveLEDs(bool endFile){
  /* Perform the Actual Light shifting */

  // Shift colors down in each column
  for (int col = 0; col < 5; ++col) {
    for (int row = LEDS_PER_COLUMN - 1; row > 0; --row) {
      columnColors[col][row] = columnColors[col][row - 1];
    }
    // Set the first LED to black (off)
    columnColors[col][0] = CRGB::Black;
  }

  // Bottom row default color should be grey/different to indicate the "strike" zone
  for (int col = 0; col < 5; ++col){
    if(columnColors[col][5] == CRGB::Black){
    columnColors[col][5] = CRGB(20, 20, 20);
  }}

  if(!endFile){
    unsigned char beat = beatmap[beat_index];
    // Serial.print("BEAT: ");
    // Serial.println((int)beat, BIN);
      if((beat & (1 << 4)) > 0) columnColors[ORANGE][0] = CRGB::OrangeRed;
      if((beat & (1 << 3)) > 0) columnColors[BLUE][0] = CRGB::Blue;
      if((beat & (1 << 2)) > 0) columnColors[YELLOW][0] = CRGB::Yellow;
      if((beat & (1 << 1)) > 0) columnColors[RED][0] = CRGB::Red;
      if((beat & (1 << 0)) > 0) columnColors[GREEN][0] = CRGB::Green;
      // TODO: Open note (0b1000000) colors all in the row white
  }
  // Update the actual leds array from our columnColors 2D array
  for (int col = 0; col < 5; ++col) {
    for (int row = 0; row < LEDS_PER_COLUMN; ++row) {
      leds[getLEDIndex(static_cast<ColorColumn>(col), row)] = columnColors[col][row];
    }
  }
  // Now that the leds array is updated, display the LEDs
  FastLED.show();

///////////////////////////////////////////////////////////////////////////////////////////
  // performTimeStepDelay(); // this happens in main loop now
}


//TODO -- need documentation of this function
int getLEDIndex(ColorColumn color_column, int index) {
  int row = color_column % 2 == 0 ? index : (LEDS_PER_COLUMN - 1 - index);
  return (color_column * LEDS_PER_COLUMN) + row;
}


// function that turns all LEDs off of last row
void clearLEDs(){
  for(int k = 0; k < LEDS_PER_COLUMN; k++) {
    leds[getLEDIndex(ORANGE, k)] = CRGB::Black;
    leds[getLEDIndex(YELLOW, k)] = CRGB::Black;
    leds[getLEDIndex(BLUE, k)] = CRGB::Black;
    leds[getLEDIndex(RED, k)] = CRGB::Black;
    leds[getLEDIndex(GREEN, k)] = CRGB::Black;
  }
  FastLED.show();
}