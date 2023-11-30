#include <SPI.h>

/* Pin configurations for controller buttons */
const int STRUM_BUTTON_UP = 4;
const int STRUM_BUTTON_DOWN = 5; //TODO -- will prob need to make this a diff pin so that uart inPin can be 5
const int RED_BUTTON = 6;
const int BLUE_BUTTON = 7;
const int GREEN_BUTTON = 8;
const int YELLOW_BUTTON = 9;
const int PURPLE_BUTTON = 10;

void hardwareCheck();

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200; // adjust as needed

const int inPin = 13;
const int outPin = 14; 