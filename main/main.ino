void setup() {
  Serial.begin(9600); // begin serial communication
  
  setupRainsensor();
  setupUvsensor();
  setupTemt6000sensor();

}

void loop() {
  // put your main code here, to run repeatedly:
  readRainsensor();
  readUvsensor();
  readTemt6000sensor();
  delay(1000);
}
