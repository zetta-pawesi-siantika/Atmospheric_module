 /*
  * Battery Level properties
  * Monitoring battery level
  */
  
 const float C = 0.38; // value from calibration
 int _analogBat;
 
void setupBatterylevel() {
  pinMode(PIN_BATTERY_LEVEL, INPUT);

}
void batteryLevel() {
  // put your main code here, to run repeatedly:
  _analogBat = analogRead(PIN_BATTERY_LEVEL);
  
  gReadbatteryvoltage = 0.009*_analogBat - 0.097 + C; // only for 4.2 Li-on battery and 10-bit ADC

  #if defined DEBUG_BATTERY_LEVEL || defined DEBUG_ALL
  Serial.print("Battery Voltage: ");
  Serial.print(gReadbatteryvoltage);
  Serial.println(" V");
  #endif
  
}
