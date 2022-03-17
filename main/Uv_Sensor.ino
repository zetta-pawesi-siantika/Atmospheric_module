/* UV sensor properties */
// signal voltage = 0 - 1 V
// it produces UV Index value

// variables local

int _readDataADCUV;
float _voltageReadUV;

// Const for local
// it was got by calculate the datasheet value ( data is linear )
const float UV_CONST = 0.85;
const float UV_SLOPE = 0.01;
const float V_REF_UV = 3300.0; // mV
const float UV_INDEX_ZERO_THRESH = 87; // calculated and tested by myself


// setup method
void setupUvsensor(){
  pinMode(UVPIN, INPUT);
  
}


// converting to UV Index 
// src: https://electropeak.com/learn/interfacing-guva-s12sd-uv-light-sensor-module-with-arduino/
void readUvsensor(){
   _readDataADCUV = analogRead(UVPIN);

   #ifdef DEBUG_UV_ADC
    Serial.print(" UV ADC Value: ");
    Serial.println(_readDataADCUV );
  #endif
  
// due to imperfect linearity of sensor, we need make special treatment for 0 - 50 mV which 87 in ADC, sensor input ( index 0). 
  if (_readDataADCUV <= UV_INDEX_ZERO_THRESH){
    _readDataADCUV = UV_INDEX_ZERO_THRESH;
  }
  
  _voltageReadUV =( _readDataADCUV / ADC_RESOLUTION)* V_REF_UV;

 

  gUvindex = (UV_SLOPE * _voltageReadUV) - UV_CONST;

  
 
  /* Serial debug */
  #if defined DEBUG_UV || defined DEBUG_ALL
    Serial.print("UV index: ");
    Serial.println(gUvindex);
  
  #endif

  #ifdef DEBUG_UV_VOLTAGE
    Serial.print(" UV Voltage (mV): ");
    Serial.println(_voltageReadUV);
  #endif

  
  
}
