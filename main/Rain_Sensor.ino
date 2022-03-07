/* Rain sensor properties */
// it produces analog value 0 - 1023 (10 bit)
// do i need convert it to another value?

// variables global
int gRaindata; 

// variables local
int _rainAnalogread;
int _limit3 = 1023; // fill with tetsing value here ...
int _limit2 = 600; // fill with tetsing value here ...
int _limit1 = 300; //fill with tetsing value here ...


// setup method 
void setupRainsensor(){
  pinMode(RAINPIN, INPUT);
}



// calibrate value for rain detection
void rainData(){
  _rainAnalogread =  analogRead(RAINPIN);

/* we have calculate the limit value for every rain condition
 *  what is the output value ?
 */

  // Condition 1
  if(_rainAnalogread <= _limit1){
    
    // write something here
    // ...
    // ...
    gRaindata = "Heavy Rainning" ;
  }
  
  // condition 2
  if(_rainAnalogread >= _limit2 && _rainAnalogread < _limit1){
    // write something ...
    //...
    //...
    gRaindata = "Rainning" ;
  }
  

  // condition 3
    if(_rainAnalogread >= _limit3 && _rainAnalogread < _limit2){
    // write something ...
    //...
    //...
    gRaindata = "Light Rainning" ;
  }

  // condition 4
    if(_rainAnalogread >= _limit3){
    // write something ...
    //...
    //...
     gRaindata = "Dry" ;
  }

/* debug menu */
  #ifdef DEBUG_RAIN_SENSOR
    Serial.print("Rain data (Analog): ");
    Serial.println(gRaindata); // debuging: shows value on serial monitor 
   #endif
    
}
