//OLED Section
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO


Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Thermocouple section
// https://github.com/RobTillaart/MAX6675
#include <MAX6675.h>
#define thermocouple_ss_pin  10



MAX6675 thermoCouple;
//encoder section
#include <MsTimer2.h>
#define ENCODER_A_PIN 2
#define ENCODER_B_PIN 3

//relay
#define RELAY_PIN A1
