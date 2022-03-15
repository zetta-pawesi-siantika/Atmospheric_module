/*  
 *   main code controls all operation. Code execute this file.
 *   see documentation here: 
*/
/* Const for Code */

/* CONST Global*/ 
#define VOLTAGE_REF_3V3 3.3 // vcc sensor's is 3.3 V
#define ADC_RESOLUTION 1023.0 // 10-bits resolution
#define DELAY_TIME 1000 


#include "Data_Capture.h"
#include "IO_Mapping.h"

// use preprocessor method (check documentation: https://docs.google.com/document/d/10_jPgvdRyReOkWolBOLf4YiwogQpMxXjzttXRmqAFns/edit)
#define DEBUG_CURAH_HUJAN

void setup() {
  Serial.begin(9600); // begin serial communication
  setupRainsensor();
  setupUvsensor();
  setupTemt6000sensor();
  setupAnemosensor();
  setupWinddirectionsensor();
  setupBme280sensor();
  setupCurahhujansensor();
  //setupDatalogger();
  //setupCom();
  setupBatterylevel();
  


}

void loop() {

  rainData();
  readUvsensor();
  readTemt6000sensor();
  readAnemosensor();
  readWinddirectionsensor();
  readBme280sensor();
  curahHujan();
  //dataLogger();
  //sendDatatoserver();
  batteryLevel();
  Serial.println();
  delay(DELAY_TIME);
  
}
