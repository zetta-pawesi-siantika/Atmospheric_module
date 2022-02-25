void setup() {
  Serial.begin(9600); // begin serial communication
  
  setupRainsensor();
  setupUvsensor();

}

void loop() {
  // put your main code here, to run repeatedly:
  readRainsensor();
  readUvsensor();
  delay(1000);
}
