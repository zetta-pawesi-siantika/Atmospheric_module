/* BME 280 sensor properties */
// it produces Temperature (deg celcius), Barometric pressure, and Humidity.

// Libraries
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)


//  object creation
Adafruit_BME280 bme; // I2C


// variables global
float gTemperature;
float gPressure;
float gHumidity;
const float BAROMETRIC_CONST = 100.0F;

// setup method
void setupBme280sensor() {
  unsigned status;
  // default settings
  status = bme.begin();
  // You can also pass in a Wire library object like &Wire2
  // status = bme.begin(0x76, &Wire2)
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
    Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(), 16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }
  Serial.println("-- Default Test --");
  Serial.println();
}

void readBme280sensor() {
  gTemperature = bme.readTemperature();
  gPressure = bme.readPressure()/ BAROMETRIC_CONST;
  gHumidity = bme.readHumidity();
  
  Serial.print("Temperature = ");
  Serial.print(gTemperature);
  Serial.println(" °C");

  Serial.print("Pressure = ");
  Serial.print(gPressure);
  Serial.println(" hPa");

  Serial.print("Humidity = ");
  Serial.print(gHumidity);
  Serial.println(" %");
  Serial.println();
}
