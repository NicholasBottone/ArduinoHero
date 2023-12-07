// #include <FastLED.h>
// #include "Gameboard.h"

// // Create a 2D array to represent the 5 columns and their respective LED colors
// CRGB columnColors[5][LEDS_PER_COLUMN];

// CRGB leds[NUM_LEDS];

// int notecount = 0;
// float BPM = 96 * 4;
// // float BPM = 190 * 4; // one step closer (linkin park)

// float exactDelay = 60000.0 / BPM; // Exact delay time in milliseconds
// float cumulativeDrift = 0.0; // To track the drift over time during the loop


// void setup() {
//   delay(2000);
//   FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
//   FastLED.clear();
//   FastLED.show();
// }

// void loop() {
//   notecount += 1;
//   // Shift colors down in each column
//   for (int col = 0; col < 5; ++col) {
//     // Shift down
//     for (int row = LEDS_PER_COLUMN - 1; row > 0; --row) {
//       columnColors[col][row] = columnColors[col][row - 1];
//     }
//     // Set the first LED to black (off)
//     columnColors[col][0] = CRGB::Black;
//   }

//   // Randomly choose a column to turn on the first LED with its color
//   if(notecount % 4 == 0){
//   ColorColumn chosenColumn = static_cast<ColorColumn>(random(5));
//   ColorColumn chosenColumn2 = static_cast<ColorColumn>(random(5));
//   switch (chosenColumn) {
//     case ORANGE: columnColors[chosenColumn][0] = CRGB::OrangeRed; break;
//     case BLUE: columnColors[chosenColumn][0] = CRGB::Blue; break;
//     case YELLOW: columnColors[chosenColumn][0] = CRGB::Yellow; break;
//     case RED: columnColors[chosenColumn][0] = CRGB::Red; break;
//     case GREEN: columnColors[chosenColumn][0] = CRGB::Green; break;
//   }
//   switch (chosenColumn2) {
//     case ORANGE: columnColors[chosenColumn2][0] = CRGB::OrangeRed; break;
//     case BLUE: columnColors[chosenColumn2][0] = CRGB::Blue; break;
//     case YELLOW: columnColors[chosenColumn2][0] = CRGB::Yellow; break;
//     case RED: columnColors[chosenColumn2][0] = CRGB::Red; break;
//     case GREEN: columnColors[chosenColumn2][0] = CRGB::Green; break;
//   }
//   }

//   // Update the actual leds array from our columnColors 2D array
//   for (int col = 0; col < 5; ++col) {
//     for (int row = 0; row < LEDS_PER_COLUMN; ++row) {
//       leds[getLEDIndex(static_cast<ColorColumn>(col), row)] = columnColors[col][row];
//     }
//   }

//   // Now that the leds array is updated, display the LEDs
//   FastLED.show();

//   // Wait a little bit before the next iteration (timestep)
//   // Calculate drift
//   int delayTime = (int)exactDelay; // Truncated delay time
//   cumulativeDrift += (exactDelay - delayTime); // Update cumulative drift

//   // Compensate for drift
//   if (cumulativeDrift >= 1.0) {
//     delayTime += 1; // Compensate by adding 1 ms to the delay
//     cumulativeDrift -= 1.0; // Subtract the compensated drift
//   }

//   Serial.print("cumulative drift: ");
//   Serial.println(cumulativeDrift);

//   // Delay for the adjusted time
//   delay(delayTime);
// }

// int getLEDIndex(ColorColumn color_column, int index) {
//   // Assuming a simple linear mapping of index to led array position
//   int row = color_column % 2 == 0 ? index : (LEDS_PER_COLUMN - 1 - index);
//   return (color_column * LEDS_PER_COLUMN) + row;
// }
