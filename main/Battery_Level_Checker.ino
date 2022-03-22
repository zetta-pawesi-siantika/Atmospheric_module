 /*
  * Battery Level properties
  * Monitoring battery level
  */
float R1 = 30000.0; //  
float R2 = 7500.0; // 

float _vout;
 int _analogBat;
 
void setupBatterylevel() {
  pinMode(PIN_BATTERY_LEVEL, INPUT);

}
void batteryLevel() {
  // put your main code here, to run repeatedly:
  _analogBat = analogRead(PIN_BATTERY_LEVEL);
  _vout = (_analogBat * VOLTAGE_REF_5V) /ADC_RESOLUTION;
  gReadbatteryvoltage = _vout / (R2/(R1+R2)); // only for 4.2 Li-on battery and 10-bit ADC

  #if defined DEBUG_BATTERY_LEVEL || defined DEBUG_ALL
  Serial.print("Battery Voltage: ");
  Serial.print(gReadbatteryvoltage);
  Serial.println(" V");
  #endif
  
}
