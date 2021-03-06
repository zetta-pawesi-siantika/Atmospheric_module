/*Data logger properties
 * this function is to log sensors data and stores it in micro SD Card
 * Max. micro sd card memory: 16 GB
*/


#include <SPI.h>
#include <SD.h>

File dataFile;

void setupDatalogger()
{
  pinMode(SS, OUTPUT);
  dataFile = SD.open(F("ATM.txt"), FILE_WRITE);
 
  // template for title
  dataFile.println(F("Date,Time Stamp,Rain Intens(0-3),Uv Index,Luminosity(Lux),Solar Irradiance(W/m2),PAR(µmoles/m2/s),Wind spd(m/s),Wind Direction,Temp(C),pressure(hPa),Humd(%)"));
}

void dataLogger()
{ 
  dataFile.println( dateNow + ","+ timeNow + "," + String(gRaindata)+ "," + String(gUvindex)+ "," + String(gLux)+ "," + String(gIrradiance)+ ","+ String(gPAR)+ "," + String(gWindspeed)+ "," + String(gWinddirectiondata)+ "," + String(gTemperature)+ ","+ String(gPressure)+ ","+ String(gHumidity));
  #if defined DEBUG_LOGGER || defined DEBUG_ALL
  Serial.println(F("data Logged"));
  #endif
  dataFile.flush();
  
}
