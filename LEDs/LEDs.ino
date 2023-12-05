#include <FastLED.h>
#include "Gameboard.h"

attachInterrupt(inPin, uartReceive, CHANGE);

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
  delay(2000);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical

  Serial1.begin(9600); //for UART from guitar console
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
  // Move a single white led 
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

int getLEDIndex(ColorColumn color_column, int index) {
  int row = color_column % 2 == 0 ? index : (LEDS_PER_COLUMN - 1 - index);
  return (color_column * LEDS_PER_COLUMN) + row;
}
