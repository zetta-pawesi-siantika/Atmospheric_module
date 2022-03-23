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
#define BYTE_LENGTH 10
#define LED 27

char gRainfallrate_char[BYTE_LENGTH];
byte i = 0;


#include "Data_Capture.h"
#include "IO_Mapping.h"

// use preprocessor method (check documentation: https://docs.google.com/document/d/10_jPgvdRyReOkWolBOLf4YiwogQpMxXjzttXRmqAFns/edit)
#define DEBUG_ALL

void setup() {
  pinMode(PIN_TRIGGER_RTC, OUTPUT);
  digitalWrite(PIN_TRIGGER_RTC, LOW); // enable RTC module

  Serial.begin(9600); // begin serial communication
  Serial1.begin(9600);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);


  setupCom();
  setupRainsensor();
  setupUvsensor();
  setupTemt6000sensor();
  setupAnemosensor();
  setupWinddirectionsensor();
  setupBme280sensor();
  setupCurahhujansensor();
  setupBatterylevel();
  setupDatalogger();
}

void loop() {

  while (Serial1.available() == 0) {
    // do nothing when data isn't comming
  }

  // if something come from serial
  while (Serial1.available() > 0) {
     Serial1.readBytes(gRainfallrate_char, BYTE_LENGTH);
    
    digitalWrite(LED, HIGH);
    delay(800);
    digitalWrite(LED, LOW);
    delay(800);

  }
  // convert data in string data type
  gWaterfallrate_str = String(gRainfallrate_char);

  Serial.println(gWaterfallrate_str);
  
  // turn on led for 5 secs. ending read data
  digitalWrite(LED, HIGH);
  delay(5000);
  digitalWrite(LED, LOW);



  rainData();
  readUvsensor();
  readTemt6000sensor();
  readAnemosensor();
  readWinddirectionsensor();
  readBme280sensor();
  curahHujan();
  batteryLevel();
  dataLogger();
  //sendDatatoserver();
  Serial.println();
  delay(DELAY_TIME);
  Serial1.write("DONE", 10);
  digitalWrite(25, HIGH); // turn off RTC
  delay(2000); // send low signal for 2 secs
  //  while(1){}
}
