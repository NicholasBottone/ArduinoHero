#define LEDS_PER_COLUMN 6
#define NUM_LEDS (LEDS_PER_COLUMN * 5)

#define DATA_PIN 5
#define CLOCK_PIN 13
#define UART_IN_PIN 5 //TODO
#define UART_OUT_PIN 3

enum ColorColumn {
  ORANGE = 0,
  BLUE = 1,
  YELLOW = 2,
  RED = 3,
  GREEN = 4
};

int getLEDIndex(ColorColumn color_column, int index);
void handleControllerInput();

/* Player game data */
int combo = 0;
int score = 0;

/* send and receive buffers for UART communication */
const byte rsBufSize = 80;
byte sBuf[rsBufSize];
int sBufStart = 0;
int sBufEnd = 0;
byte rBuf[rsBufSize];
int rBufStart = 0;
int rBufEnd = 0;

/* UART helper function definitions */
void uartSend(byte B);
void uartReceive();

const int UART_PERIOD_MICROS = 104;