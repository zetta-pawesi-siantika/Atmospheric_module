/* *************************************************************************** */
/* Atmospheric Module Firmware V.1.0                                           */
/* Created by: Pawesi Siantika || 2022 || copyrights: Zettabyte Pte. Ltd.      */
/* main code is executed first.                                                */
/* see documentation here: https://bit.ly/ATM_firmdoc                          */
/* This is a full features but you have to choose 1 of data storage (Thinkspeak*/
/* Micro SD card)    !!!                                                       */
/* *************************************************************************** */

#include "Data_Capture.h"
#include "IO_Mapping.h"
#include "LowPower.h"
#include <Wire.h>
#include <DS3231.h>
#include <SPI.h>


/* CONST Global*/
#define VOLTAGE_REF_3V3 3.3 // vcc sensor's is 3.3 V
#define VOLTAGE_REF_5V 5.0 // vcc sensor's is 5.0 V
#define ADC_RESOLUTION 1024.0 // 10-bits resolution

/* Hour Operation Consts */
const byte WORK_TIME_INTERVAL = 12; // minutes
const byte RELAX_TIME_INTERVAL = 60; // relaxing operation is every 1 hour

// morning time
const byte MORNING_TIME_START = 4 ; // 4.00 am
const byte MORNING_TIME_END = 6 ; // 6.00 am

// mid Day
const byte MID_DAY_START = 11; // 11.00 am
const byte MID_DAY_END = 13 ; // 01.00 pm

// Sunset
const byte SUNSET_TIME_START = 17; // 05.00 pm
const byte SUNSET_TIME_END = 19; // 07.00 pm



// Using preprocessor method (check documentation:https://bit.ly/ATM_firmdoc)
//#define DEBUG_ALL

DS3231  rtc(SDA, SCL);
Time t;

void setup() {
  Serial.begin(9600);
  setupCom();
  setupRTCDS3231();
  setupRainsensor();
  setupUvsensor();
  setupAnemosensor();
  setupWinddirectionsensor();
  setupBme280sensor();
  setupBH1750();
  setupDatalogger();
  activateSensor();
}

void loop() {
  t = rtc.getTime();
  byte timeHournow = t.hour;

#if defined DEBUG_MAIN || defined DEBUG_ALL
  Serial.print("Hour: ");
  Serial.println(timeHournow);
#endif

  if (timeHournow >= MORNING_TIME_START && timeHournow < MORNING_TIME_END) {
    operationDevice(WORK_TIME_INTERVAL);
  }
  else if (timeHournow >= MID_DAY_START && timeHournow < MID_DAY_END) {
    operationDevice(WORK_TIME_INTERVAL);
#if defined DEBUG_MAIN || defined DEBUG_ALL
    Serial.println("Mid day");
#endif
  }
  else if (timeHournow >= SUNSET_TIME_START && timeHournow < SUNSET_TIME_END) {
    operationDevice(WORK_TIME_INTERVAL);
#if defined DEBUG_MAIN || defined DEBUG_ALL
    Serial.println("Sunset");
#endif
  }
  else {
    operationDevice(RELAX_TIME_INTERVAL);
#if defined DEBUG_MAIN || defined DEBUG_ALL
    Serial.println("Relaxing");
#endif
  }

  delay(2000); // delay before sleep
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  delay(2000); // wakeup time (don't put less value than this !!!)
}

void operationDevice(byte timeInterval) {
  if (t.min % timeInterval == 0) {
#if defined DEBUG_MAIN || defined DEBUG_ALL
    Serial.println("OPERATING");
#endif

    activateSensor();
    delay(1500);
    readSensor();
    deactivateSensor();
    dataLogger();
    sendDatatoserver();

    byte endTimeoperation = t.min;
    while (endTimeoperation == t.min ) {
      t = rtc.getTime();
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      delay(2000);
    }

  } else {
#if defined DEBUG_MAIN || defined DEBUG_ALL
    Serial.println("SLEEPING");
#endif
  }
}

void activateSensor() {
  // relay ssr ON
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void deactivateSensor() {
  // relay ssr OFF
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
  readTimennow();
}
