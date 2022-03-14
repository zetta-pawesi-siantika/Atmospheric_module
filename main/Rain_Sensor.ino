/* Rain sensor properties */
// it produces analog value 0 - 1023 (10 bit)
// do i need convert it to another value?


// variables local
int _rainAnalogread;
int _threshold = 1000; // threshold to determine rainfall


// setup method 
void setupRainsensor(){
  pinMode(RAINPIN, INPUT);
}



// calibrate value for rain detection
void rainData(){
  _rainAnalogread =  analogRead(RAINPIN);

  if ( _rainAnalogread <= _threshold){
    gRaindata = "RAINING";

  }else{
    gRaindata = "NO RAINING";
  }

/* debug menu */
  #if defined DEBUG_RAIN_SENSOR || defined DEBUG_ALL
    Serial.print("Rain data : ");
    Serial.println(gRaindata); // debuging: shows value on serial monitor 
    Serial.println(_rainAnalogread);
   #endif
    
}
