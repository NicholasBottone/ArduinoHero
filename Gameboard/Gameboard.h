#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <FastLED.h>
#include <LiquidCrystal.h>

#define LEDS_PER_COLUMN 6
#define NUM_LEDS (LEDS_PER_COLUMN * 5)

#include "songs.h"

//LED pin
#define DATA_PIN A2

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
#define UP_BTN A1

// LED Setup
CRGB leds[NUM_LEDS];
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);


/* Loaded Song Data*/
Song curr_song;
unsigned char *beatmap = new unsigned char(0b11111111); // By default is a beatmap with only a "terminate" note (0b11111111 = 255 = the stop code)
float *bpm_values = {};
int *bpm_change_indexes = {};

/* Song runtime data*/
unsigned int beat_index = 0; // idxof current beat the song is on
unsigned int bpm_index = 0; // idxof current bpm the song is playing at 
int song_num = 0; // index in the songList

unsigned long nextUpdateTime = 0; // This is how we do tempo (we dont use delay, we set the next updatetime)

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
void displayCountdown_LCD(int countdown);
void displayGame_LCD(int max_combo, int curr_combo);
void displayEnd_LCD(int max_combo);

// Watchdog timer functions
void setupWatchdogTimer(); // for call on initialization
void enableWatchdogTimer(); // for call inside the FSM when we want to start the timer
void disableWatchdogTimer(); // for call inside the FSM when we want to stop the timer
void resetWatchdogTimer(); // for repeatedly calling to "pet" the watchdog timer
void WDT_Handler(); // for handling the watchdog timer interrupt

#endif // GAMEBOARD_H
