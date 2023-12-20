#ifndef MOCK_LIQUIDCRYSTAL_H
#define MOCK_LIQUIDCRYSTAL_H

class LiquidCrystal {
public:
  LiquidCrystal(int rs, int e, int d4, int d5, int d6, int d7) {}

  int cursorRow;
  char* firstRow;
  char* secondRow;

  void begin(int cols, int rows) {}
  void clear() {}
  void home() {}
  void setCursor(int col, int row) {
    cursorRow = row;
  }
  void write(uint8_t value) {}
  void print(const char* s) {
    if (cursorRow == 0) {
      firstRow = (char*)s;
    } else {
      secondRow = (char*)s;
    }
  }
};

#endif // MOCK_LIQUIDCRYSTAL_H
