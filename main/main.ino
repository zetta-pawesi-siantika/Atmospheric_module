void setup() {
  Serial.begin(9600); // begin serial communication
  
  setupRainsensor();
  setupUvsensor();
  setupTemt6000sensor();
  setupAnemosensor();

}

void loop() {
  // put your main code here, to run repeatedly:
  readRainsensor();
  readUvsensor();
  readTemt6000sensor();
  readAnemosensor();
  delay(1000);
}
