/* ******************************************************************** */
/* This sketch file is used to initialize IO pin on ARDUINO MEGA 2560   */
/* board                                                                */
/* Created by: Pawesi Siantika || 2022                                        */
/* ******************************************************************** */

/* No needs declare Pin */
/* many peripherals don't need require initilize Pin, there are:
  1. DS32331 -> I2C on D20 and D21
  2. BME 280 -> I2C
  3. Data Logger -> SPI (D50-D4)
*/


/* Analog pin */
/* block starts here */
 /* UV sensor */
#define UVPIN A0
/* TEMT6000 sensor */
#define TEMT6000PIN  A1
/* rain sensor */
#define RAINPIN A3
/* MQ 135 MQ Sensor */
#define MQPIN A4 
/* Anemometer */
#define ANEMOMETERPIN A5

/* analog pin block ends here */


/* Digital Pin */
/* block starts here */
/* Wind Direction */
#define N 11   // North 
#define NE 3  // North East
#define E 4   // East
#define SE 5  // South East
#define S 6   // South
#define SW 7  //South West
#define W 8   // West
#define NW 9  // North West

/* Digital pin block ends here */
