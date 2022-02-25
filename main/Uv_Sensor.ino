/* UV sensor properties */
// it produces value 0 - 1023 (10 bit)

// variables global
int gUvdata;

// setup method
void setupUvsensor(){
  pinMode(UVPIN, INPUT);
  
}

void readUvsensor(){
  gUvdata = analogRead(UVPIN);
  Serial.print("UV data (Analog): ");
  Serial.println(gUvdata); // debuging: shows value on serial monitor 
}
