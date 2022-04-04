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
#define DEBUG_ALL

void setup() {
  Wire.begin(10);
  pinMode(PIN_TRIGGER_RTC, OUTPUT);
  digitalWrite(PIN_TRIGGER_RTC, LOW); // disable RTC module


  Serial.begin(9600); // begin serial communication
  setupCom();
  Serial.println("Com");
  setupRTCDS3231();
    Serial.println("1");
  setupRainsensor();
    Serial.println("1");
  setupUvsensor();
    Serial.println("1");
  setupAnemosensor();
    Serial.println("1");
  setupWinddirectionsensor();
    Serial.println("1");
//  setupBme280sensor();
//     Serial.println("280");
  setupBH1750();
     Serial.println("BH");
  setupBatterylevel();
     Serial.println("Bat");
  setupDatalogger();
     Serial.println("data");
}

void loop() {

  rainData();
  readUvsensor();
  readAnemosensor();
  readWinddirectionsensor();
//  readBme280sensor();
  readBH1750sensor();
  batteryLevel();
  printTimennow();
    dataLogger();
    sendDatatoserver();

  Serial.println();
  delay(DELAY_TIME);
  digitalWrite(25, HIGH); // turn off RTC
  delay(2000); // send low signal for 2 secs

}
