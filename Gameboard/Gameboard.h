#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#define LEDS_PER_COLUMN 6
#define NUM_LEDS (LEDS_PER_COLUMN * 5)

#include <LiquidCrystal.h>
#include "songs.h"

//LED pin
#define DATA_PIN A2 //TODO - CAN THIS MOVE?

//Controller pin
#define UART_IN_PIN 7

//LCD pins
#define rs 0
#define e 1
#define d4 2
#define d5 3
#define d6 4
#define d7 5
#define START_BTN 6
#define UP_BTN A1 //TODO - see if this works

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];
const unsigned int BEATMAP_SIZE = 26;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// unsigned char beatmap[BEATMAP_SIZE] = {
//   0b00001101, 0b00000001, 0b00011000, 0b00001101, 0b00000011,
//   0b00001101, 0b00000001, 0b00011000, 0b00001101, 0b00000011,
//   0b00001101, 0b00000001, 0b00011000, 0b00001101, 0b00000011,
//   0b00001101, 0b00000001, 0b00011000, 0b00001101, 0b00000011,
//   0b00001101, 0b00000001, 0b00011000, 0b00001101, 0b00000011,
  // 0b11111111};
unsigned char *beatmap = songList[0].beats;

unsigned int beat_index = 0;
int song_num = 0;

/* Player game data */
int combo = 0;
int combo_max = 0;
int score = 0;
int countdown = 3;

/*
 * Type (enum and struct) definitions for state & color columns for LEDs
 */
typedef enum {
  ORANGE = 0,
  BLUE = 1,
  YELLOW = 2,
  RED = 3,
  GREEN = 4
} ColorColumn;

typedef enum {
  sSONG_MENU = 5,
  sCOUNTDOWN = 6,
  sUPDATE_GAME = 7,
  sGAME_OVER = 8,
} state;

//LED board functions
int getLEDIndex(ColorColumn color_column, int index);
void moveLEDs();
void clearLEDs();

// //communication functions (UNO and Controller)
void handleControllerInput();
// int receiveFromUno();
void uartDelay(unsigned long ltime);
void uartReceive();

// LCD screen functions
void displayStart_LCD(bool upButtonPress, bool startButtonPress);
void displayCoundown_LCD(int countdown);
void displayGame_LCD(int max_combo, int curr_combo);
void displayEnd_LCD(int max_combo);

#endif // GAMEBOARD_H
