void setup() {
  Serial.begin(9600); // begin serial communication
  
  setupRainsensor();

}

void loop() {
  // put your main code here, to run repeatedly:
  readRainsensor();
  delay(1000);
  

}
