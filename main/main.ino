/*  
 *   main code controls all operation. Code execute this file.
 *   see documentation here: 
*/
/* Const for Code */


#include "Data_Capture.h"

// use preprocessor to use special method
#define DEBUG_BME280

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
  readUvsensor();
  readTemt6000sensor();
  readAnemosensor();
  readWinddirectionsensor();
  readMq135sensor();
  readBme280sensor();
  delay(1000);;
  
}
