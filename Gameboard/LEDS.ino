#include <FastLED.h>
#include "Gameboard.h"

// This function moves the LEDs Down the LED display
void moveLEDs() {
  for(int k = 0; k < LEDS_PER_COLUMN; k++) {
    // Turn our current led on to white, then show the leds

    unsigned char beat = beatmap[beat_index];

    // Serial.println((int) beat, BIN);

    if((beat & (1 << 4)) > 0) leds[getLEDIndex(ORANGE, k)] = CRGB::OrangeRed;
    if((beat & (1 << 3)) > 0) leds[getLEDIndex(YELLOW, k)] = CRGB::Yellow;
    if((beat & (1 << 2)) > 0) leds[getLEDIndex(BLUE, k)] = CRGB::Blue;
    if((beat & (1 << 1)) > 0) leds[getLEDIndex(RED, k)] = CRGB::Red;
    if((beat & (1 << 0)) > 0) leds[getLEDIndex(GREEN, k)] = CRGB::Green;

    // Show the leds (only one of which is set to white, from above)
    FastLED.show();

    // Wait a little bit
    delay(400);

    // Turn our current led back to black for the next loop around
    leds[getLEDIndex(ORANGE, k)] = CRGB::Black;
    leds[getLEDIndex(YELLOW, k)] = CRGB::Black;
    leds[getLEDIndex(BLUE, k)] = CRGB::Black;
    leds[getLEDIndex(RED, k)] = CRGB::Black;
    leds[getLEDIndex(GREEN, k)] = CRGB::Black;
  }
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
}