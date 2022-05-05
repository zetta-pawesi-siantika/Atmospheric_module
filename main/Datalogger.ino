/*Data logger properties
 * this function is to log sensors data and stores it in micro SD Card
*/


#include <SPI.h>
#include <SD.h>

File dataFile;

void setupDatalogger()
{
  pinMode(SS, OUTPUT);
  
  if (!SD.begin(CHIP_SELECT)) {
    Serial.println(F("Card failed, or not present"));
  }
  

  dataFile = SD.open(F("ATM.txt"), FILE_WRITE);
  if (! dataFile) {
    Serial.println(F("error opening file.txt"));
  
  }
  // template for title
  //dataFile.println(F(" Date,Time Stamp,Rain Intens,Uv Index,Lux,Solar Irradiance(W/m2),PAR(µmoles/m2/s),Wind spd(m/s),Wind Direction,Temp(C),pressure(hPa),Humd(%)"));
}

void dataLogger()
{ 
  dataFile.println( dateNow + ","+ timeNow + "," + String(gRaindata)+ "," + String(gUvindex)+ "," + String(gLux)+ "," + String(gIrradiance)+ ","+ String(gPAR)+ "," + String(gWindspeed)+ "," + String(gWinddirectiondata)+ "," + String(gTemperature)+ ","+ String(gPressure)+ ","+ String(gHumidity));
  #if defined DEBUG_LOGGER || defined DEBUG_ALL
  Serial.println(F("data Logged"));
  #endif
  dataFile.flush();
  
}
