/* *************************************************************************** */
/* This sketch file is used to initialize IO pin on ARDUINO PRO MINI 5V 16 MHZ */
/* board                                                                       */
/* Created by: Pawesi Siantika || 2022                                         */
/* *************************************************************************** */

#ifndef IO_MAPPING_H
#define IO_MAPPING_H

/* No needs declare Pin */
/* many peripherals don't need require initilize Pin, there are:
  1. DS32331 -> I2C on D20 and D21
  2. BME 280 -> I2C
  3. Data Logger -> SPI (10-13)
  4. BH1750  -> I2C
*/
#define CHIP_SELECT 10 // SS pin on Arduino PRO MINI (Micro SD Card property)
/* Analog pin */
/* block starts here */
 /* UV sensor */
#define UVPIN A0
/* rain sensor */
#define RAINPIN A1 
/* Anemometer */
#define ANEMOMETERPIN A2
/* Battery Level */
#define PIN_BATTERY_LEVEL A3
/* Wind vane*/
#define W A6   // West
#define NW A7 // North West

/* analog pin block ends here */


/* Digital Pin */
/* block starts here */
/* Wind Direction */
#define N 4   // North 
#define NE 5  // North East
#define E 6   // East
#define SE 7  // South East
#define S 8   // South
#define SW 9  //South West


/* Digital pin block ends here */

#endif
