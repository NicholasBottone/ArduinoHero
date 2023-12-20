#ifndef MOCK_ARDUINO_H
#define MOCK_ARDUINO_H

unsigned long mockMillis = 0;

void setMillis(unsigned long millis) {
  mockMillis = millis;
}

unsigned long myMillis() {
  #ifdef TESTING
    return mockMillis;
  #else
    return millis();
  #endif
}

#endif // MOCK_ARDUINO_H
