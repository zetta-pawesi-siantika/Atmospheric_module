/* This file contains BH1750 sensor. It measures lux actually but we can measure irradiance and PAR using conversion
 *  
 */
 
#include <BH1750.h>

BH1750 lightMeter;

void setupBH1750() {
  lightMeter.begin();
}

void readBH1750sensor() {
  PROGMEM const float IRRADIANCE_CONST = 0.0079;
  PROGMEM const float PAR_CONST = 0.004764;
  PROGMEM const float PAR_SLOPE = 0.01770;

  gLux = lightMeter.readLightLevel();
  gIrradiance = gLux * IRRADIANCE_CONST; // conversion
  gPAR = PAR_SLOPE * gLux + PAR_CONST; // conversion

#if defined DEBUG_BH1750 || defined DEBUG_ALL
  Serial.print(F("Light: "));
  Serial.print(gLux);
  Serial.println(F(" lx"));

  Serial.print(F("Irradiance: "));
  Serial.print(gIrradiance);
  Serial.println(F(" W/m2"));

  Serial.print(F("PAR: "));
  Serial.print(gPAR);
  Serial.println(F(" µmoles/m2/s"));

#endif
}
