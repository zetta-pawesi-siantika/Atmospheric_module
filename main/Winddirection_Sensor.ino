/* Winddirection sensor properties */
// it produces wind direction value (String)

// setup method
void setupWinddirectionsensor(){
  pinMode(N, INPUT_PULLUP);
  pinMode(NE, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
  pinMode(SE, INPUT_PULLUP);
  pinMode(S, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);
  pinMode(W, INPUT_PULLUP);
  pinMode(NW, INPUT_PULLUP);
}

void readWinddirectionsensor(){
if (digitalRead(N) == LOW) {
    gWinddirectiondata = 90; // 0 deg = NORTH
  }
  else if (digitalRead(NE) == LOW) {
    gWinddirectiondata = 45; // NORTH EAST
  }
  else if (digitalRead(E) == LOW) {
    gWinddirectiondata = 0; // EAST
  }
  else if (digitalRead(SE) == LOW) {
    gWinddirectiondata = 315; // SOUTH EAST
  }
  else if (digitalRead(S) == LOW) {
    gWinddirectiondata = 270; // SOUTH
  }
  else if (digitalRead(SW) == LOW) {
    gWinddirectiondata = 225; // SOUTH WEST
  }
  else if (digitalRead(W) == LOW) {
    gWinddirectiondata = 180; // WEST
  }
  else if (digitalRead(NW) == LOW) {
    gWinddirectiondata = 135; // NORTH WEST
  }

/* Serial Debug */
#if defined DEBUG_WIND_DIRECTION || defined DEBUG_ALL
  Serial.print("Wind direction: ");
  Serial.print(gWinddirectiondata);
  Serial.println(" \xc2\xb0"); // degree symbol in char
 #endif
}
