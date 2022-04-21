#include <SoftwareSerial.h>
#include <String.h>

#define APN "m2mautotronic" // Nb-IoT telkomsel
#define API_KEY "GX42QNGG2Z7JHL19" // ThinkSpeak API key (keep it secret)
#define API_KEY_BATTERY "HOUJ7UB20NJDSRCK" // Battery + Light parameter

SoftwareSerial SIM808(SERIAL_RX,SERIAL_TX); // RX || TX on Arduino Pro Mini

void setupCom()
{
  SIM808.begin(9600);               // the GPRS baud rate
  delay(1000);
}

void sendDatatoserver()
{
  if (SIM808.available())
    Serial.write(SIM808.read());

  SIM808.println("AT");
  delay(1000);

  SIM808.println("AT+CPIN?");
  delay(1000);

  SIM808.println("AT+CREG?");
  delay(1000);

  SIM808.println("AT+CGATT?");
  delay(1000);

  SIM808.println("AT+CIPSHUT");
  delay(1000);

  SIM808.println("AT+CIPSTATUS");
  delay(2000);

  SIM808.println("AT+CIPMUX=0");
  delay(2000);

  ShowSerialData();

  SIM808.println("AT+CSTT=\"" + String(APN) + "\""); //start task and setting the APN,
  delay(1000);

  ShowSerialData();

  SIM808.println("AT+CIICR");//bring up wireless connection
  delay(3000);

  ShowSerialData();

  SIM808.println("AT+CIFSR");//get local IP adress
  delay(2000);

  ShowSerialData();

  SIM808.println("AT+CIPSPRT=0");
  delay(3000);

  ShowSerialData();

  SIM808.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);

  ShowSerialData();

  SIM808.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();

  // Sensors channel
  String str = "GET https://api.thingspeak.com/update?api_key=" + String(API_KEY) + "&field1=" + String(gWindspeed) + "&field2=" + String(gPressure) + "&field3=" + String(gTemperature) + "&field4=" + String(gRaindata) + "&field5=" + String(gLux) + "&field6=" + String(gUvindex) + "&field7=" + String(gWinddirectiondata) + "&field8=" + String(gHumidity);
  Serial.println(str);
  SIM808.println(str);//begin send data to remote server

  delay(4000);
  ShowSerialData();

  SIM808.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet
  SIM808.println();

  // Battery
   SIM808.println("AT+CIPSPRT=0");
  delay(3000);

  ShowSerialData();

  SIM808.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);

  ShowSerialData();
  SIM808.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();
  //  // Battery channel
  String strBat = "GET https://api.thingspeak.com/update?api_key=" + String(API_KEY_BATTERY) + "&field2=" + String(gIrradiance)+ "&field3=" + String(gPAR);
  Serial.println(strBat);
  SIM808.println(strBat);//begin send data to remote server

  delay(4000);
  ShowSerialData();

  SIM808.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet
  SIM808.println();

  ShowSerialData();

  SIM808.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
}
void ShowSerialData()
{
  while (SIM808.available() != 0)
    Serial.write(SIM808.read());
  delay(5000);

}
