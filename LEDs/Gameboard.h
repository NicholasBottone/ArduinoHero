#define LEDS_PER_COLUMN 6
#define NUM_LEDS (LEDS_PER_COLUMN * 5)

#define DATA_PIN 5
#define UART_IN_PIN 7


/* Player game data */
int combo = 0;
int combo_max = 0;
int score = 0;

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

int getLEDIndex(ColorColumn color_column, int index);
void handleControllerInput();
int receiveFromUno();
void moveLEDs();

/* UART helper function definitions */
void uartDelay(unsigned long ltime);
void uartReceive();

const int UART_PERIOD_MICROS = 104;