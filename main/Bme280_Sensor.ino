/* BME 280 sensor properties 
 *  it measures Temperature (deg celcius), Barometric pressure, and Humidity.
 */

#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; 

void setupBme280sensor() {
  unsigned status;
  status = bme.begin(0x76, &Wire); // IT SHOULD BE DECLARED LIKE THIS!!!
}

void readBme280sensor() {
  PROGMEM const float BAROMETRIC_CONST = 100.0F;
  gTemperature = bme.readTemperature();
  gPressure = bme.readPressure()/ BAROMETRIC_CONST;
  gHumidity = bme.readHumidity();

  #if defined DEBUG_BME280 || defined DEBUG_ALL
    Serial.print("Temperature = ");
    Serial.print(gTemperature);
    Serial.println(" °C");
  
    Serial.print("Pressure = ");
    Serial.print(gPressure);
    Serial.println(" hPa");
  
    Serial.print("Humidity = ");
    Serial.print(gHumidity);
    Serial.println(" %");
   #endif
}
