/* Rain sensor properties */
// it produces analog value 0 - 1023 (10 bit)

// variables
int rainData; 

// setup method 
void setupRainsensor(){
  pinMode(RAINPIN, INPUT);
}

void readRainsensor(){
  rainData =  analogRead(RAINPIN);
  Serial.println(rainData);
}
