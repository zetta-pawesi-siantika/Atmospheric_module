/*  
 *   main code controls all operation. Code execute this file.
 *   see documentation here: 
*/
/* Const for Code */


#include "Data_Capture.h"
#include "IO_Mapping.h"

// use preprocessor method (check documentation: https://docs.google.com/document/d/10_jPgvdRyReOkWolBOLf4YiwogQpMxXjzttXRmqAFns/edit)
#define DEBUG_UV
#define DEBUG_UV_VOLTAGE
#define DEBUG_UV_ADC

void setup() {
  Serial.begin(9600); // begin serial communication
  setupRainsensor();
  setupUvsensor();
  setupTemt6000sensor();
  setupAnemosensor();
  setupWinddirectionsensor();
  setupBme280sensor();
  //setupDatalogger();


}

void loop() {

  rainData();
  readUvsensor();
  readTemt6000sensor();
  readAnemosensor();
  readWinddirectionsensor();
  readBme280sensor();
  //dataLogger();
  delay(DELAY_TIME);
  
}
