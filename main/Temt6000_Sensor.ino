/* TEMT6000 (light ambient)  sensor properties */
// it produces value 0 - 1023 (10 bit)

// variables global
int gTemt6000data;

// setup method
void setupTemt6000sensor(){
  pinMode(TEMT6000PIN, INPUT);
  
}

void readTemt6000sensor(){
  gTemt6000data = analogRead(TEMT6000PIN);
  Serial.println(gTemt6000data); // debuging: shows value on serial monitor 
}
