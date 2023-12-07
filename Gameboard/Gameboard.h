#define LEDS_PER_COLUMN 6
#define NUM_LEDS (LEDS_PER_COLUMN * 5)

//LED pin
#define DATA_PIN 5

//Controller pin
#define UART_IN_PIN 7

//LCD pins
const int rs = 0, e = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
#define START_BTN 6;
#define UP_BTN 7; //TODO - THIS NEEDS TO GO IN ANOTHER PIN

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);


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
  sSONG_MENU = 1,
  sCOUNTDOWN = 2,
  sGAME = 3,
  sGAME_OVER = 4,
} state;

//LED board functions
int getLEDIndex(ColorColumn color_column, int index);
void moveLEDs();

//communication functions (UNO and Controller)
void handleControllerInput();
int receiveFromUno();
void uartDelay(unsigned long ltime);
void uartReceive();

const int UART_PERIOD_MICROS = 104;

// LCD screen functions
void displayStart_LCD(bool upButtonPress, bool startButtonPress);
void displayCoundown_LCD(int countdown);
void displayGame_LCD(int max_combo, int curr_combo);
void displayEnd_LCD(int max_combo);