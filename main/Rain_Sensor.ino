/* Rain sensor properties */
// it produces analog value 0 - 1023 (10 bit)

// variables global
int gRaindata; 

// setup method 
void setupRainsensor(){
  pinMode(RAINPIN, INPUT);
}

void readRainsensor(){
  gRaindata =  analogRead(RAINPIN);
  Serial.println(gRaindata);
}
