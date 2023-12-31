#include "Gameboard.h"

bool beat_queue[6][5];

// Create a 2D array to represent the 5 columns and their respective LED colors
CRGB columnColors[5][LEDS_PER_COLUMN];

float cumulativeDrift = 0.0; // To track the drift over time during the loop

// this function delays between notes in a beatmap based on BPM and drift
void performTimeStepDelay(unsigned long start_beat_millis){
  #ifndef TESTING
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
      bpm_index++; // Move to the next BPM value for the next beat
  }
  #else
  outputFunctionsCalled += "performTimeStepDelay(" + String(start_beat_millis) + ")\n";
  #endif
}

void moveLEDs(bool endFile){
  #ifndef TESTING
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
      if((beat & (1 << 4)) > 0) columnColors[ORANGE][0] = CRGB::OrangeRed;
      if((beat & (1 << 3)) > 0) columnColors[BLUE][0] = CRGB::Blue;
      if((beat & (1 << 2)) > 0) columnColors[YELLOW][0] = CRGB::Yellow;
      if((beat & (1 << 1)) > 0) columnColors[RED][0] = CRGB::Red;
      if((beat & (1 << 0)) > 0) columnColors[GREEN][0] = CRGB::Green;
  }
  // Update the actual leds array from our columnColors 2D array
  for (int col = 0; col < 5; ++col) {
    for (int row = 0; row < LEDS_PER_COLUMN; ++row) {
      leds[getLEDIndex(static_cast<ColorColumn>(col), row)] = columnColors[col][row];
    }
  }
  // Now that the leds array is updated, display the LEDs
  FastLED.show();
  #else
  outputFunctionsCalled += "moveLEDs(" + String(endFile) + ")\n";
  #endif
}


// function that gets the LED index for a given color column
int getLEDIndex(ColorColumn color_column, int index) {
  int row = color_column % 2 == 0 ? index : (LEDS_PER_COLUMN - 1 - index);
  return (color_column * LEDS_PER_COLUMN) + row;
}

// function that turns all LEDs off of last row
void clearLEDs(){
  #ifndef TESTING
  for(int k = 0; k < LEDS_PER_COLUMN; k++) {
    leds[getLEDIndex(ORANGE, k)] = CRGB::Black;
    leds[getLEDIndex(YELLOW, k)] = CRGB::Black;
    leds[getLEDIndex(BLUE, k)] = CRGB::Black;
    leds[getLEDIndex(RED, k)] = CRGB::Black;
    leds[getLEDIndex(GREEN, k)] = CRGB::Black;
  }
  FastLED.show();
  #else
  outputFunctionsCalled += "clearLEDs()\n";
  #endif
}
