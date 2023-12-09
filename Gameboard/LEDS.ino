#include <FastLED.h>
#include "Gameboard.h"

bool beat_queue[6][5];

// Create a 2D array to represent the 5 columns and their respective LED colors
CRGB columnColors[5][LEDS_PER_COLUMN];

int notecount = 0;
float BPM = 96 * 2;
// float BPM = 190 * 4; // one step closer (linkin park)

float calculatedDelay = 60000.0 / BPM; // Exact delay time in milliseconds
float cumulativeDrift = 0.0; // To track the drift over time during the loop

unsigned int queue_index = 0;

void moveLEDs(bool endFile){
  // Get the BPM that we should be moving the notes at
  

  notecount += 1;
  // Shift colors down in each column
  for (int col = 0; col < 5; ++col) {
    // Shift down
    for (int row = LEDS_PER_COLUMN - 1; row > 0; --row) {
      columnColors[col][row] = columnColors[col][row - 1];
    }
    // Set the first LED to black (off)
    columnColors[col][0] = CRGB::Black;
  }

  // Randomly choose a column to turn on the first LED with its color
  if(!endFile){
    unsigned char beat = beatmap[beat_index];
    
    Serial.print("BEAT: ");
    Serial.println((int)beat, BIN);

    // if(notecount % 4 == 0){
      if((beat & (1 << 4)) > 0) columnColors[ORANGE][0] = CRGB::OrangeRed;
      if((beat & (1 << 3)) > 0) columnColors[BLUE][0] = CRGB::Blue;
      if((beat & (1 << 2)) > 0) columnColors[YELLOW][0] = CRGB::Yellow;
      if((beat & (1 << 1)) > 0) columnColors[RED][0] = CRGB::Red;
      if((beat & (1 << 0)) > 0) columnColors[GREEN][0] = CRGB::Green;
    // }
  }
  

  // Update the actual leds array from our columnColors 2D array
  for (int col = 0; col < 5; ++col) {
    for (int row = 0; row < LEDS_PER_COLUMN; ++row) {
      leds[getLEDIndex(static_cast<ColorColumn>(col), row)] = columnColors[col][row];
    }
  }

  // Now that the leds array is updated, display the LEDs
  FastLED.show();

  // Wait a little bit before the next iteration (timestep)
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