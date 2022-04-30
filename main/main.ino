/*
     main code controls all operation. Code execute in this file.
     see documentation here:
*/

#include "Data_Capture.h"
#include "IO_Mapping.h"
#include <Wire.h>
#include <DS3231.h>
#include "LowPower.h"
#include <SPI.h>

/* CONST Global*/
#define VOLTAGE_REF_3V3 3.3 // vcc sensor's is 3.3 V
#define VOLTAGE_REF_5V 5.0 // vcc sensor's is 5.0 V
#define ADC_RESOLUTION 1023.0 // 10-bits resolution
#define DELAY_TIME 1000
#define RELAY_PIN 4

// preprocessor write here --> it enabels or disables features
#define DEBUG_LOGGER

/* Hour Operation */
const byte workTimeinterval = 10; // minutes
const byte relaxTimeinterval = 59; // night operation every 1 hour

// morning time
const byte morningTimestart = 4 ; // 4.00 am
const byte morningTimeend = 6 ; // 6.00 am

// mid Day
const byte middayTimestart = 11; // 11.00
const byte middayTimeend = 13 ; // 13.00

// Sunset
const byte sunsetTimestart = 17; // 17.00
const byte sunsetTimeend = 19; // 19.00

byte timeIntervalTest = 20; // sec

bool statusOperation;

// use preprocessor method (check documentation: https://docs.google.com/document/d/10_jPgvdRyReOkWolBOLf4YiwogQpMxXjzttXRmqAFns/edit)
//#define

DS3231  rtc(SDA, SCL);
Time t;

void setup() {
  Wire.begin(2); // i2c address
  Serial.begin(9600); // begin serial communication
  //setupCom();
  setupRTCDS3231();
  setupRainsensor();
  setupUvsensor();
  setupAnemosensor();
  setupWinddirectionsensor();
  setupBme280sensor();
  setupBH1750();
  setupDatalogger();
}

void loop() {

  t = rtc.getTime();
  byte timeHournow = t.hour;
  Serial.println(t.hour);
  delay(500);

  if (timeHournow >= morningTimestart && timeHournow < morningTimeend) {

    operationDevice(workTimeinterval);
    Serial.println("Morning");
  }
  else if (timeHournow >= middayTimestart && timeHournow < middayTimeend) {
    operationDevice(workTimeinterval);
    Serial.println("Mid day");
  }
  else if (timeHournow >= sunsetTimestart && timeHournow < sunsetTimeend) {
    operationDevice(workTimeinterval);
    Serial.println("Sunset");
  }
  else {
    operationDevice(relaxTimeinterval);
    Serial.println("Relaxing");
  }

  delay(1000); // sleep before delay
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  delay(500); // wakeup time
}

void operationDevice(byte timeInterval) {
  if (t.min % timeInterval == 0) {
    Serial.println("OPERATING");
    activateSensor();
    readSensor();
    deactivateSensor();
    dataLogger();
    //sendDatatoserver();

    byte endTimeoperation = t.min;
    while (endTimeoperation == t.min ) {
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      delay(500);
    }

  } else {
    Serial.println("SLEEPING");
  }
}


void activateSensor() {
  // relay ssr ON
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void deactivateSensor() {
  // relay ssr OFF
  //pinMode(4, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  // return the pin mode to pull up (belongs to wind direction (north))
  pinMode(N, INPUT_PULLUP);
}

void readSensor() {
  readAnemosensor();
  readBH1750sensor();
  readBme280sensor();
  readRainsensor();
  readUvsensor();
  readWinddirectionsensor();
}
