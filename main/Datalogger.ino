/*Data logger properties
 * this function is to log sensors data and stores it in micro SD Card
*/

//Libraries
#include <SPI.h>
#include <SD.h>
//#include "Data_Capture.h"

// PIN Definition


// Global Conts 
String FILE_TITLE ="ATM_TEST.txt";

// Local Conts 
String TEMPLATE_TITLE =" Date,Time Stamp,Rain Intens,Uv Index,Lux,Solar Irradiance(W/m2),PAR(µmoles/m2/s),Wind spd(m/s),Wind Direction,Temp(C),pressure(hPa),Humd(%)"; 

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
    Serial.println("error opening" + FILE_TITLE );
  
  }
  // template for title
  dataFile.println(TEMPLATE_TITLE);
  Serial.println(TEMPLATE_TITLE);
}

void dataLogger()
{
  // make a string for assembling the data to log:
  String dataString = "";


  dataString = dataString +  dateNow + ","+ timeNow + "," + String(gRaindata)+ "," + String(gUvindex)+ "," + String(gLux)+ "," + String(gIrradiance)+ ","+ String(gPAR)+ "," + String(gWindspeed)+ "," + String(gWinddirectiondata)+ "," + String(gTemperature)+ ","+ String(gPressure)+ ","+ String(gHumidity); 
  dataFile.println(dataString);
  #if defined DEBUG_LOGGER || defined DEBUG_ALL
  Serial.println(dataString);
  #endif
  dataFile.flush();\
  
}
