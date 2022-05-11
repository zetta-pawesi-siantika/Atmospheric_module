/* This file contains Wind direction sensors properties
 *  It measures direction of wind in degree
 *  src: https://www.depoinovasi.com/produk-776-sensor-arah-angin.html
 */

void setupWinddirectionsensor(){
  pinMode(N, INPUT_PULLUP);
  pinMode(NE, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
  pinMode(SE, INPUT_PULLUP);
  pinMode(S, INPUT_PULLUP); // hardware is broken
  pinMode(SW, INPUT_PULLUP);

}

void readWinddirectionsensor(){
if (digitalRead(N) == LOW) {
    gWinddirectiondata = 0; // = NORTH
  }
  else if (digitalRead(NE) == LOW) {
    gWinddirectiondata = 45; // NORTH EAST
  }
  else if (digitalRead(E) == LOW) {
    gWinddirectiondata = 90; // EAST
  }
  else if (digitalRead(SE) == LOW) {
    gWinddirectiondata = 135; // SOUTH EAST
  }
  else if (digitalRead(S) == LOW) { // hardware is broken. 
    gWinddirectiondata = 180; // SOUTH
  }
  else if (digitalRead(SW) == LOW) {
    gWinddirectiondata = 225; // SOUTH WEST
  }
  else if (analogRead(W) <= 100) { // using analog pin (A6), LOW voltage in ADC value is under 100.
    gWinddirectiondata = 270; // WEST
  }
  else if (analogRead(NW) <= 100) {// using analog pin (A7), LOW voltage in ADC value is under 100.
    gWinddirectiondata = 315; // NORTH WEST
  }else
  {
    gWinddirectiondata = 180; // SOUTH (THIS IS TEMPORER SOLUTION DUE TO HARDWARE BROKEN ON SOUTH DIRECTION (PIN D5 Sensor)
  }

#if defined DEBUG_WIND_DIRECTION || defined DEBUG_ALL
  Serial.print(F("Wind direction: "));
  Serial.print(gWinddirectiondata);
  Serial.println(F(" \xc2\xb0")); // degree symbol in char
 #endif
}
