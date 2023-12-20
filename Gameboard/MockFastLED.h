#ifndef MOCK_FASTLED_H
#define MOCK_FASTLED_H

class CRGB {
public:
  int r;
  int g;
  int b;

  CRGB() : r(0), g(0), b(0) {}
  CRGB(int red, int green, int blue) : r(red), g(green), b(blue) {}

  bool operator==(const CRGB& other) const {
    return r == other.r && g == other.g && b == other.b;
  }

  static const CRGB Black;
  static const CRGB Blue;
  static const CRGB Green;
  static const CRGB OrangeRed;
  static const CRGB Red;
  static const CRGB Yellow;
};

const CRGB CRGB::Black = CRGB(0, 0, 0);
const CRGB CRGB::Blue = CRGB(0, 0, 255);
const CRGB CRGB::Green = CRGB(0, 255, 0);
const CRGB CRGB::OrangeRed = CRGB(255, 69, 0);
const CRGB CRGB::Red = CRGB(255, 0, 0);
const CRGB CRGB::Yellow = CRGB(255, 255, 0);

class CFastLED {
public:
  CFastLED() {}

  CRGB* ledsArray;
  int numLeds;
  
  template <int LED_TYPE, int DATA_PIN, int COLOR_ORDER>
  void addLeds(CRGB* ledsArray, int numLeds) {
    this->ledsArray = ledsArray;
    this->numLeds = numLeds;
  }
  void clear() {}
  void show() {}
};

CFastLED FastLED;

#define WS2812B 0
#define A2 0
#define GRB 0

#endif // MOCK_FASTLED_H
