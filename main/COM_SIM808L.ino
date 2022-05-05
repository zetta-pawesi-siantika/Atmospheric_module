/* SIM808L properties
    Please notice APIKEY from Thinkspeak
    and APN setting
*/

#include <SoftwareSerial.h>

SoftwareSerial SIM808(SERIAL_RX, SERIAL_TX);

void setupCom()
{
  SIM808.begin(9600);
}

void sendDatatoserver()
{
  if (SIM808.available())
    Serial.write(SIM808.read());

  SIM808.println(F("AT"));
  delay(1000);

  SIM808.println(F("AT+CPIN?"));
  delay(1000);

  SIM808.println(F("AT+CREG?"));
  delay(1000);

  SIM808.println(F("AT+CGATT?"));
  delay(1000);

  SIM808.println(F("AT+CIPSHUT"));
  delay(1000);

  SIM808.println(F("AT+CIPSTATUS"));
  delay(2000);

  SIM808.println(F("AT+CIPMUX=0"));
  delay(2000);

  ShowSerialData();

  SIM808.println(F("AT+CSTT=m2mautotronic")); //start task and setting the APN,
  delay(3000);

  ShowSerialData();


  SIM808.println(F("AT+CIICR"));//bring up wireless connection
  delay(3000);

  ShowSerialData();


  SIM808.println(F("AT+CIFSR"));//get local IP adress
  delay(2000);

  ShowSerialData();
  SIM808.println(F("AT+CIPSPRT=0"));
  delay(3000);

  ShowSerialData();

  SIM808.println(F("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\""));//start up the connection
  delay(6000);

  ShowSerialData();

  SIM808.println(F("AT+CIPSEND"));//begin send data to remote server
  delay(4000);
  ShowSerialData();

  // Sensors channel
  SIM808.print(F("GET https://api.thingspeak.com/update?api_key=GX42QNGG2Z7JHL19"));//begin send data to remote server
  delay(1000);
  SIM808.println(+ "&field1=" + String(gWindspeed) + "&field2=" + String(gPressure) + "&field3=" + String(gTemperature) + "&field4=" + String(gRaindata) + "&field5=" + String(gUvindex) + "&field6=" + String(gWinddirectiondata) + "&field7=" + String(gHumidity));
  delay(2000);
  ShowSerialData();

  SIM808.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet
  SIM808.println();

  SIM808.println(F("AT+CIPSPRT=0"));
  delay(3000);

  ShowSerialData();

  SIM808.println(F("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\""));//start up the connection
  delay(6000);

  ShowSerialData();

  SIM808.println(F("AT+CIPSEND"));//begin send data to remote server
  delay(4000);
  ShowSerialData();

  // Light Parameter
  SIM808.println("GET https://api.thingspeak.com/update?api_key=HOUJ7UB20NJDSRCK&field1=" + String(gLux) + "&field2=" + String(gPAR) + "&field3=" + String(gIrradiance));//begin send data to remote server

  delay(2000);
  ShowSerialData();

  SIM808.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet
  SIM808.println();


  SIM808.println(F("AT+CIPSHUT"));//close the connection
  delay(100);
  ShowSerialData();
}
void ShowSerialData()
{
#if defined DEBUG_SIM808L || defined DEBUG_ALL
  while (SIM808.available() != 0)
    Serial.write(SIM808.read());
  delay(5000);
#endif

}
