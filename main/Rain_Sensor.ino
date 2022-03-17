/* Rain sensor properties */
// it produces analog value 0 - 1023 (10 bit)
// do i need convert it to another value?


// variables local
int _rainAnalogread;
// threshold to determine rain's intensity
int _thresholNorain= 920; // 920 - 1023
int _thresholdLightrain= 800; // 800 - 919
int _thresholdMedrain= 400; // 400 - 799
// HEAVY RAIN 0 - 399


// setup method 
void setupRainsensor(){
  pinMode(RAINPIN, INPUT);
}



// calibrate value for rain detection
void rainData(){
  _rainAnalogread =  analogRead(RAINPIN);

  if ( _rainAnalogread < _thresholdMedrain){
    gRaindata = "HEAVY RAIN";

  }
  else if (_rainAnalogread >= _thresholdMedrain && _rainAnalogread < _thresholdLightrain){
    gRaindata = "MEDIUM RAINING";
  }
   else if (_rainAnalogread >=  _thresholdLightrain && _rainAnalogread < _thresholNorain){
    gRaindata = "LIGHT RAINING";
   }
    else if (_rainAnalogread >= _thresholNorain){
    gRaindata = "NO RAINING";
   }
   
/* debug menu */
  #if defined DEBUG_RAIN_SENSOR || defined DEBUG_ALL
    Serial.print("Rain data : ");
    Serial.println(gRaindata); // debuging: shows value on serial monitor 
    Serial.println(_rainAnalogread);
   #endif
    
}
