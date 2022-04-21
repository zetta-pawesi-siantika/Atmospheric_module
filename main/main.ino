/*
     main code controls all operation. Code execute this file.
     see documentation here:
*/
/* Const for Code */

/* CONST Global*/
#define VOLTAGE_REF_3V3 3.3 // vcc sensor's is 3.3 V
#define VOLTAGE_REF_5V 5.0 // vcc sensor's is 5.0 V
#define ADC_RESOLUTION 1023.0 // 10-bits resolution
#define DELAY_TIME 1000

#include "Data_Capture.h"
#include "IO_Mapping.h"
#include <Wire.h>

// use preprocessor method (check documentation: https://docs.google.com/document/d/10_jPgvdRyReOkWolBOLf4YiwogQpMxXjzttXRmqAFns/edit)
#define DEBUG_UV

void setup() {
  /* Rule
   *  1. setup all sensor
   *  2. Setup SIM808 --> connect it to network and put it on sleep mode (Serial interrupt to wake up)
   *  3. Setup Serial begin
   */
  
  Wire.begin(10);

  Serial.begin(9600); // begin serial communication
 // setupCom();
  setupRTCDS3231();
  setupRainsensor();
  setupUvsensor();
  setupAnemosensor();
  setupWinddirectionsensor();
//  setupBme280sensor();
  setupBH1750();
  setupBatterylevel();
//  setupDatalogger();
}

void loop() {

  // read  time

  // if relax time -->  every 1 once houe

  // else if operation hour --> every 10 minutes in a hour

  // else --> sleep every 8 secs


  /*rule: operation of device:
   * 1. Turn on SSR relay (SENSORS)
   * 2. Read the data
   * 3. Store Data to SD CARD
   * 4. Send Data To Server
   * 5. end.
   */
  
   

 // rainData();
  readUvsensor();
//  readAnemosensor();
//  readWinddirectionsensor();
//  readBme280sensor();
//  readBH1750sensor();
//  //batteryLevel();
//  printTimennow();
//dataLogger();
 // sendDatatoserver();

  Serial.println();
  delay(800);
//  while(1){} // stop here
  

}
