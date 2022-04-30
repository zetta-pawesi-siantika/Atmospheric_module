/* Rain sensor properties
    it measures analog value only. We have to determine the intensity of rain.
*/

void setupRainsensor() {
  pinMode(RAINPIN, INPUT);
}

void readRainsensor() {
  int _rainAnalogread;
#define  _thresholNorain  920 // 920 - 1023
#define _thresholdLightrain 800 // 800 - 919
#define _thresholdMedrain 400 // 400 - 799
  // HEAVY RAIN ranges is from  0 - 399

  _rainAnalogread =  analogRead(RAINPIN);
  if ( _rainAnalogread < _thresholdMedrain) {
    gRaindata = 3; // Heavy rain
  }
  else if (_rainAnalogread >= _thresholdMedrain && _rainAnalogread < _thresholdLightrain) {
    gRaindata = 2; // Medium Rain
  }
  else if (_rainAnalogread >=  _thresholdLightrain && _rainAnalogread < _thresholNorain) {
    gRaindata = 1; // Light Rain
  }
  else if (_rainAnalogread >= _thresholNorain) {
    gRaindata = 0;// No Rain
  }


#if defined DEBUG_RAIN_SENSOR || defined DEBUG_ALL
  Serial.print(F("Rain data : "));
  Serial.println(gRaindata); 
  Serial.println(_rainAnalogread);
#endif

}
