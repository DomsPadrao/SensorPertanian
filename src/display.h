#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// pre-define DEBUG when compiling to enable debug
#ifdef DEBUG

#include "debug.h"

#endif


// Screen constants parameters
const int SCREEN_WIDTH = 128;   // OLED display width, in pixels
const int SCREEN_HEIGHT = 64;   // OLED display height, in pixels
const int SCREEN_SDA = 5;
const int SCREEN_SCL = 4;
const int SCREEN_ADDR = 0x3C;

void setup_display();

void display_splash_screen();

void display_data(
    const int& nitrogen, const int& phosphorus, const int& kalium,
    const float& pH, const float& temperature, const float& humidity,
    const int& EC
);