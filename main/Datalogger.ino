/*Data logger properties
 * this function is to log sensors data and stores it in micro SD Card
*/

//Libraries
#include <SPI.h>
#include <SD.h>

// PIN Definition
const byte CHIP_SELECT = 53; // SS pin on Arduino MEGA BOARD (IT HAS PUT HERE. NO IN IO_MAPPING TAB)

// Global Conts 
String FILE_TITLE ="ATM_Data.txt";

// Local Conts 
String TEMPLATE_TITLE =" || Rain || Uv Index || Light Intens(%) || Wind spd(m/s) ||  Wind Dir || CO(PPM) | Alcohol(PPM) | CO2(PPM) | NH4(PPM) | TOLUNEO(PPM) | ACETONA(PPM) || Temp(C) | pressure(hPa) | Humd(%)  || "; 

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
}

void dataLogger()
{
  // make a string for assembling the data to log:
  String dataString = "";

  //dataString += String(gRaindata); //+ String(gUvdata)+ String(gTemt6000data) + String(gWindspeed)+ String(gWinddirection) + String(gCo)+ String(gAlcohol)+ String(gCo2)+ String(gToluneo) + String(Nh4)+ String(gAcetona);

  
  dataFile.println(dataString);
  Serial.println(dataString);
  dataFile.flush();
  
  // Take 1 measurement every 500 milliseconds
  delay(500);
}
