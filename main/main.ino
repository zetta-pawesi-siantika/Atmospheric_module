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
#define DEBUG_ALL

void setup() {
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  digitalWrite(25, HIGH); // enable RTC module
  digitalWrite(24, HIGH); // booting up SIM808L
  delay(2000); // giving signal to SIM808L for 2 minutes
  digitalWrite(24, LOW); // booting up SIM808L
  
  Serial.begin(9600); // begin serial communication
  setupRainsensor();
  setupUvsensor();
  setupTemt6000sensor();
  setupAnemosensor();
  setupWinddirectionsensor();
  setupBme280sensor();
  setupCurahhujansensor();
  setupBatterylevel();
  setupDatalogger();
  setupCom();
 
  
  


}

void loop() {

  rainData();
  readUvsensor();
  readTemt6000sensor();
  readAnemosensor();
  readWinddirectionsensor();
  readBme280sensor();
  curahHujan();
  batteryLevel();
  dataLogger();
  sendDatatoserver();
  Serial.println();
  delay(DELAY_TIME);
  digitalWrite(25, LOW); // turn off RTC
  delay(10000); // send low signal for 10 secs
  
}
