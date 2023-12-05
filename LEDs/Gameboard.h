#define LEDS_PER_COLUMN 6
#define NUM_LEDS (LEDS_PER_COLUMN * 5)

#define DATA_PIN 5
#define UART_IN_PIN 7


/* Player game data */
int combo = 0;
int score = 0;

enum ColorColumn {
  ORANGE = 0,
  BLUE = 1,
  YELLOW = 2,
  RED = 3,
  GREEN = 4
};

int getLEDIndex(ColorColumn color_column, int index);
void handleControllerInput();

/* UART helper function definitions */
void uartDelay(unsigned long ltime);
void uartReceive();

const int UART_PERIOD_MICROS = 104;