#include <Arduino.h>
#include <Adafruit_GPS.h>
#include <PeripheralNames.h> //smm - added to try to eliminate link-error: "undefined reference to `UARTClass::UARTClass(UARTName)'"

// Test code for Ultimate GPS Using Hardware Serial
// (e.g. GPS for Leonardo, Flora or FeatherWing)
//
// This code shows how to test a passthru between USB and hardware serial
//
// Tested and works great with the Adafruit GPS FeatherWing
// ------> https://www.adafruit.com/products/3133
// or Flora GPS
// ------> https://www.adafruit.com/products/1059
// but also works with the shield, breakout
// ------> https://www.adafruit.com/products/1272
// ------> https://www.adafruit.com/products/746
//
// Pick one up today at the Adafruit electronics shop
// and help support open source hardware & software! -ada


// what's the name of the hardware serial port?


//#define Serial1
UARTClass Serial1;


void setup() {
  // wait for hardware serial to appear
  while (!Serial);

  // make this baud rate fast enough to we aren't waiting on it
  Serial.begin(115200);

  // 9600 baud is the default rate for the Ultimate GPS
  Serial1.begin(9600);
}


void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial1.write(c);
  }
  if (Serial1.available()) {
    char c = Serial1.read();
    Serial.write(c);
  }
}