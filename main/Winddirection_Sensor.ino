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
    gWinddirectiondata = "NORTH";
  }
  else if (digitalRead(NE) == LOW) {
    gWinddirectiondata = "NORTH EAST";
  }
  else if (digitalRead(E) == LOW) {
    gWinddirectiondata = "EAST";
  }
  else if (digitalRead(SE) == LOW) {
    gWinddirectiondata = "SOUTH EAST";
  }
  else if (digitalRead(S) == LOW) {
    gWinddirectiondata = "SOUTH";
  }
  else if (digitalRead(SW) == LOW) {
    gWinddirectiondata = "SOUTH WEST";
  }
  else if (digitalRead(W) == LOW) {
    gWinddirectiondata = "WEST";
  }
  else if (digitalRead(NW) == LOW) {
    gWinddirectiondata = "NORTH WEST";
  }

/* Serial Debug */
#ifdef DEBUG_WIND_DIRECTION
  Serial.println(gWinddirectiondata);
 #endif
}
