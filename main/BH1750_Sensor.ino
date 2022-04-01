/*

  Example of BH1750 library usage.

  This example initialises the BH1750 object using the default high resolution
  continuous mode and then makes a light level reading every second.

  Connections

  - VCC to 3V3 or 5V
  - GND to GND
  - SCL to SCL (A5 on Arduino Uno, Leonardo, etc or 21 on Mega and Due, on
    esp8266 free selectable)
  - SDA to SDA (A4 on Arduino Uno, Leonardo, etc or 20 on Mega and Due, on
    esp8266 free selectable)
  - ADD to (not connected) or GND

  ADD pin is used to set sensor I2C address. If it has voltage greater or equal
  to 0.7VCC voltage (e.g. you've connected it to VCC) the sensor address will be
  0x5C. In other case (if ADD voltage less than 0.7 * VCC) the sensor address
  will be 0x23 (by default).

*/

#include <BH1750.h>
#include <Wire.h>

BH1750 lightMeter;

void setupBH1750() {
  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  lightMeter.begin();
}

void readBH1750sensor() {
  float lux = lightMeter.readLightLevel();
  float irr = (lux * 0.0079);
  float PAR = 0.01770*lux + 0.004764;

#if defined DEBUG_BH1750 || defined DEBUG_ALL
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  
  Serial.print("Irradiance: ");
  Serial.print(irr);
  Serial.println(" W/m2");

  Serial.print("PAR: ");
  Serial.print(PAR);
  Serial.println("µmoles/m2/s");

 #endif
}
