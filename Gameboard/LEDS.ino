#include <FastLED.h>
#include "Gameboard.h"

bool beat_queue[6][5];

// Create a 2D array to represent the 5 columns and their respective LED colors
CRGB columnColors[5][LEDS_PER_COLUMN];


float cumulativeDrift = 0.0; // To track the drift over time during the loop

unsigned int queue_index = 0;

void performTimeStepDelay(){
  /* Based on the current tempo, resolution, previous drift, etc... determine the appropriate amount of delay to stay on time w/ the music*/

  // Check for bpm change (if the beat_index == value of the next item in bpm_change_indexes)
  // TODO ...? remember to increment and blah blah blah

  // Get the BPM that we should be moving the notes at
  float current_bpm = curr_song.bpm_values[bpm_index];
  Serial.print("current bpm:");
  Serial.println(current_bpm);

  float calculatedDelay = 60000.0 / current_bpm; // TODO: Incorporate resolution and eventually stretch etc...

  // Calculate drift
  int actualDelay = (int)calculatedDelay; // Truncated delay time
  cumulativeDrift += (calculatedDelay - actualDelay); // Update cumulative drift

  // Compensate for drift
  if (cumulativeDrift >= 1.0) {
    actualDelay += 1; // Compensate by adding 1 ms to the delay
    cumulativeDrift -= 1.0; // Subtract the compensated drift
  }

  Serial.print("cumulative drift: ");
  Serial.println(cumulativeDrift);

  // Delay for the adjusted time
  delay(actualDelay);
}

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
  if(!endFile){
    unsigned char beat = beatmap[beat_index];
    Serial.print("BEAT: ");
    Serial.println((int)beat, BIN);
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
  performTimeStepDelay();
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