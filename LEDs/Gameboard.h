#define LEDS_PER_COLUMN 6
#define NUM_LEDS (LEDS_PER_COLUMN * 5)

#define DATA_PIN 5
#define CLOCK_PIN 13

enum ColorColumn {
  ORANGE = 0,
  BLUE = 1,
  YELLOW = 2,
  RED = 3,
  GREEN = 4
};

int getLEDIndex(ColorColumn color_column, int index);

/* UART helper function definitions */
void uartSend(byte B);
void uartReceive();
const int UART_PERIOD_MICROS = 104;

const int inPin = 5; //TODO
const int outPin = 3; //TODO