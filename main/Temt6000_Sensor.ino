/* TEMT6000 (light ambient)  sensor properties */
// it produces light intensity (%)
// src: https://how2electronics.com/temt6000-ambient-light-sensor-arduino-measure-light-intensity/

// Const for TEMT6000 light intensity
const float CONST_LIGHT = 0.0976;


// setup method
void setupTemt6000sensor(){
  pinMode(TEMT6000PIN, INPUT);
  
}

void readTemt6000sensor(){
  
  gTemt6000data = analogRead(TEMT6000PIN)* CONST_LIGHT; // light intensity (%)

  #if defined DEBUG_TEMT6000 || defined DEBUG_ALL
    Serial.print("TEMT6000 data / light intensity: ");
    Serial.print(gTemt6000data); // debuging: shows value on serial monitor 
    Serial.println(" %");
   #endif
    
}
