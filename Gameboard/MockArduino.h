#ifndef MOCK_ARDUINO_H
#define MOCK_ARDUINO_H

unsigned long mockMillis = 0;

void setMillis(unsigned long millis) {
  mockMillis = millis;
}

unsigned long millis() {
  return 0;
}

#endif // MOCK_ARDUINO_H
