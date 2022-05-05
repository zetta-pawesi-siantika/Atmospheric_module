/* this file contains RTC DS3231. It gives date and time
 *  
 */
void setupRTCDS3231(){
   rtc.begin();
}

void readTimennow(){
  dateNow = rtc.getDateStr();
  timeNow = rtc.getTimeStr();
  
  #if defined DEBUG_RTCDS3231 || defined DEBUG_ALL
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
