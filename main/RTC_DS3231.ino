
void setupRTCDS3231(){
   rtc.begin();
}

void readTimennow(){
  dayOftheWeek = rtc.getDOWStr();
  dateNow = rtc.getDateStr();
  timeNow = rtc.getTimeStr();
  
  #if defined DEBUG_RTCDS3231 || defined DEBUG_ALL
    // Send Day-of-Week
  Serial.print(dayOftheWeek);
  Serial.print(" ");
  
  // Send date
  Serial.print(dateNow);
  Serial.print(" -- ");

  // Send time
  Serial.println(timeNow);
  #endif
}

byte getHour(){
  t = rtc.getTime();
  hourNow =  t.hour;
  return hourNow;
}

byte getMinute(){
  t = rtc.getTime();
  minuteNow =  t.min;
  return minuteNow;
}
