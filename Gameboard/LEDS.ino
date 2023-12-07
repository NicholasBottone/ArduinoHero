#include <FastLED.h>
#include "Gameboard.h"

// This function moves the LEDs Down the LED display
void moveLEDs() {
  for(int i = 0; i < LEDS_PER_COLUMN; i++) {
    // Turn our current led on to white, then show the leds
    leds[getLEDIndex(ORANGE, i)] = CRGB::OrangeRed;
    leds[getLEDIndex(YELLOW, i)] = CRGB::Yellow;
    leds[getLEDIndex(BLUE, i)] = CRGB::Blue;
    leds[getLEDIndex(RED, i)] = CRGB::Red;
    leds[getLEDIndex(GREEN, i)] = CRGB::Green;

    // Show the leds (only one of which is set to white, from above)
    FastLED.show();

    // Wait a little bit
    delay(400);

    // Turn our current led back to black for the next loop around
    leds[getLEDIndex(ORANGE, i)] = CRGB::Black;
    leds[getLEDIndex(YELLOW, i)] = CRGB::Black;
    leds[getLEDIndex(BLUE, i)] = CRGB::Black;
    leds[getLEDIndex(RED, i)] = CRGB::Black;
    leds[getLEDIndex(GREEN, i)] = CRGB::Black;
  }
}

//TODO -- need documentation of this function
int getLEDIndex(ColorColumn color_column, int index) {
  int row = color_column % 2 == 0 ? index : (LEDS_PER_COLUMN - 1 - index);
  return (color_column * LEDS_PER_COLUMN) + row;
}