/* This file contains GUVA 12 sensor (UV sensor)
 *  It measures UV index (0-11)
 *  src: https://electropeak.com/learn/interfacing-guva-s12sd-uv-light-sensor-module-with-arduino/
 * 
 */
   
void setupUvsensor() {
  pinMode(UVPIN, INPUT);
}


void readUvsensor() {
  int _readDataADCUV;
  float _voltageReadUV;

  PROGMEM const float UV_SLOPE = 0.01;
  PROGMEM const float V_REF_UV = 3300.0; // mV

  _readDataADCUV = analogRead(UVPIN);

  _voltageReadUV = ( _readDataADCUV / ADC_RESOLUTION) * V_REF_UV;
  gUvindex = (UV_SLOPE * _voltageReadUV);

  // check negative value, set gUvindex = 0;
  if (gUvindex < 0) {
    gUvindex = 0.0;
  }

#if defined DEBUG_UV || defined DEBUG_ALL
  Serial.print(F("UV index: "));
  Serial.println(gUvindex);
#endif
}
