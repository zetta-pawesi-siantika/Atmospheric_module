/* Anemometer sensor properties 
 *  It produces wind speed value
 *  src: https://www.instructables.com/How-to-Use-a-Adafruit-Anemometer-Sensor-With-Ardui/
 */

void setupAnemosensor() {
  pinMode(ANEMOMETERPIN, INPUT);
}

void readAnemosensor() {
  float _anesensorVoltage = 0; 
  int _anesensorValue = 0; 
  
  PROGMEM const float _anevoltageConversionConstant = .004882814;
  PROGMEM const float _anevoltageMin = .4; 
  PROGMEM const byte _anewindSpeedMin = 0; 
  PROGMEM const float _anevoltageMax = 2.0; 
  PROGMEM const byte _anewindSpeedMax = 32; 

  _anesensorValue = analogRead(ANEMOMETERPIN); 
  _anesensorVoltage = _anesensorValue * _anevoltageConversionConstant; 

  if (_anesensorVoltage <= _anevoltageMin) {
    gWindspeed = 0; 
  } else {
    gWindspeed = (_anesensorVoltage - _anevoltageMin) * _anewindSpeedMax / (_anevoltageMax - _anevoltageMin); //For voltages above minimum value, use the linear relationship to calculate wind speed.
  }

#if defined DEBUG_ANEMO || defined DEBUG_ALL
  Serial.print(F("Voltage: "));
  Serial.print(_anesensorVoltage);
  Serial.print("\t");
  Serial.print(F("Wind speed: "));
  Serial.println(gWindspeed);
#endif

}
