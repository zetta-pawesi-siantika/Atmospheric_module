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
String TEMPLATE_TITLE =" || Rain || Uv Index || Light Intens(%) || Wind spd(m/s) ||  Wind Dir || Temp(C) | pressure(hPa) | Humd(%) | Battery Level|| "; 

File dataFile;

void setupDatalogger()
{
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);
  
  if (!SD.begin(CHIP_SELECT)) {
    Serial.println("Card failed, or not present");
    while (1) ;
  }
  Serial.println("card initialized.");
  

  dataFile = SD.open(FILE_TITLE, FILE_WRITE);
  if (! dataFile) {
    Serial.println("error opening datalog.txt");
    while (1) ;
  }
  // template for title
  dataFile.println(TEMPLATE_TITLE);
  Serial.println(TEMPLATE_TITLE);
}

void dataLogger()
{
  // make a string for assembling the data to log:
  String dataString = "";

  dataString = dataString + String(gRaindata)+ "  ||  " + String(gUvindex)+ "  || " + String(gTemt6000data)+ "  || " + String(gWindspeed)+ "  || " + String(gWinddirectiondata)+ "  || " + String(gTemperature)+ "  || "+ String(gPressure)+ "  || "+ String(gHumidity)+ "  || " +String(gReadbatteryvoltage)+ "||" ;

  #if defined LOGGER || defined DEBUG_ALL
  dataFile.println(dataString);
  Serial.println(dataString);
  #endif
  dataFile.flush();\
  
}
