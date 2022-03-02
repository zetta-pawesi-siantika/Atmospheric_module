#include <DS3232RTC.h>  //RTC Library https://github.com/JChristensen/DS3232RTC
void setup() {
  Serial.begin(9600); // begin serial communication
  
  setupRainsensor();
  setupUvsensor();
  setupTemt6000sensor();
  setupAnemosensor();
  setupWinddirectionsensor();
  setupMq135sensor();
  setupBme280sensor();


}

void loop() {

  rainData();
//  readUvsensor();
  readTemt6000sensor();
  readAnemosensor();
  readWinddirectionsensor();
  readMq135sensor();
  readBme280sensor();
  delay(1000);;
  
}
