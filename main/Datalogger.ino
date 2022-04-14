/*Data logger properties
 * this function is to log sensors data and stores it in micro SD Card
*/

//Libraries
#include <SPI.h>
#include <SD.h>
//#include "Data_Capture.h"

// PIN Definition


// Global Conts 
String FILE_TITLE ="ATM_1.txt";

// Local Conts 
String TEMPLATE_TITLE =" | Rain Intens | Uv Index | Lux | Solar Irradiance (W/m2) | PAR (µmoles/m2/s) | Wind spd(m/s) |  Wind Dir | Temp(C) | pressure(hPa) | Humd(%) | Battery Level(V) |"; 

File dataFile;

void setupDatalogger()
{
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);
  
  if (!SD.begin(CHIP_SELECT)) {
    Serial.println("Card failed, or not present");
   
  }
  Serial.println("card initialized.");
  

  dataFile = SD.open(FILE_TITLE, FILE_WRITE);
  if (! dataFile) {
    Serial.println("error opening datalog.txt");
  
  }
  // template for title
  dataFile.println(TEMPLATE_TITLE);
  Serial.println(TEMPLATE_TITLE);
}

void dataLogger()
{
  // make a string for assembling the data to log:
  String dataString = "";

  // added day/month/year/Time
  dataFile.print(dayOftheWeek);
  dataFile.print(" ");
  dataFile.print(dateNow);
  dataFile.print(" ");
  dataFile.println(timeNow);
  

  dataString = dataString + String(gRaindata)+ "  ,  " + String(gUvindex)+ "  , " + String(gLux)+ "  , "+ "  , " + String(gIrradiance)+ "  , "+ "  , " + String(gPAR)+ "  , " + String(gWindspeed)+ "  , " + String(gWinddirectiondata)+ "  , " + String(gTemperature)+ "  , "+ String(gPressure)+ "  , "+ String(gHumidity)+ "  , " +String(gReadbatteryvoltage)+ ","; 
  #if defined LOGGER || defined DEBUG_ALL
  dataFile.println(dataString);
  Serial.println(dataString);
  #endif
  dataFile.flush();\
  
}
