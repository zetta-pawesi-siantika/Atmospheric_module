/* UV sensor properties */
// signal voltage = 0 - 1 V
// it produces UV Index value

// variables global
int gUvdata;

// variables local
byte _uvIndex;
int _readDataADCUV;
float _voltageReadUV;


// setup method
void setupUvsensor(){
  pinMode(UVPIN, INPUT);
  
}


// converting to UV Index 
// src: https://electropeak.com/learn/interfacing-guva-s12sd-uv-light-sensor-module-with-arduino/
void _convertTouvindex(){
  _readDataADCUV = analogRead(UVPIN);
  _voltageReadUV = _readDataADCUV / ADC_RESOLUTION;

  if(_voltageReadUV < 50){
    gUvdata = 0;
  }
  else if(50 <= _voltageReadUV && _voltageReadUV < 227){
    gUvdata = 1;
  }
  else if(227 <= _voltageReadUV && _voltageReadUV < 318){
    gUvdata = 2;
  }
  else if(318 <= _voltageReadUV && _voltageReadUV < 408){
    gUvdata = 3;
  }
  else if(408 <= _voltageReadUV && _voltageReadUV < 503){
    gUvdata = 4;
  }
  else if(503 <= _voltageReadUV && _voltageReadUV < 606){
    gUvdata = 5;
  }
  else if(606 <= _voltageReadUV && _voltageReadUV < 696){
    gUvdata = 6;
  }
  else if(696 <= _voltageReadUV && _voltageReadUV < 795 ){
    gUvdata = 7;
  }
  else if(795 <= _voltageReadUV && _voltageReadUV < 881){
    gUvdata = 8;
  }
  else if(881 <= _voltageReadUV && _voltageReadUV < 976){
    gUvdata = 9;
  }
  else if(976 <= _voltageReadUV && _voltageReadUV < 1079){
    gUvdata = 10;
  }
  else if(1079 >= _voltageReadUV ){
    gUvdata = 11;
  }
  
  
  
}
