
#include <SoftwareSerial.h>


#include <String.h>

#define APN "m2mautotronic" // Nb-IoT telkomsel
#define API_KEY "GX42QNGG2Z7JHL19" // ThinkSpeak API key (keep it secret)
#define API_KEY_BATTERY "HOUJ7UB20NJDSRCK" // Battery + Light parameter


void setupCom()
{
  pinMode(BOOTING_SIM808, OUTPUT);
  digitalWrite(BOOTING_SIM808, HIGH); // booting up SIM808L
  delay(2000); // giving signal to SIM808L for 2 minutes
  digitalWrite(BOOTING_SIM808, LOW); 
  Serial3.begin(9600);               // the GPRS baud rate
  delay(1000);
}

void sendDatatoserver()
{


  if (Serial3.available())
    Serial.write(Serial3.read());

  Serial3.println("AT");
  delay(1000);

  Serial3.println("AT+CPIN?");
  delay(1000);

  Serial3.println("AT+CREG?");
  delay(1000);

  Serial3.println("AT+CGATT?");
  delay(1000);

  Serial3.println("AT+CIPSHUT");
  delay(1000);

  Serial3.println("AT+CIPSTATUS");
  delay(2000);

  Serial3.println("AT+CIPMUX=0");
  delay(2000);

  ShowSerialData();

  Serial3.println("AT+CSTT=\"" + String(APN) + "\""); //start task and setting the APN,
  delay(1000);

  ShowSerialData();

  Serial3.println("AT+CIICR");//bring up wireless connection
  delay(3000);

  ShowSerialData();

  Serial3.println("AT+CIFSR");//get local IP adress
  delay(2000);

  ShowSerialData();

  Serial3.println("AT+CIPSPRT=0");
  delay(3000);

  ShowSerialData();

  Serial3.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);

  ShowSerialData();

  Serial3.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();

  // Sensors channel
  String str = "GET https://api.thingspeak.com/update?api_key=" + String(API_KEY) + "&field1=" + String(gWindspeed) + "&field2=" + String(gPressure) + "&field3=" + String(gTemperature) + "&field4=" + String(gRaindata) + "&field5=" + String(gLux) + "&field6=" + String(gUvindex) + "&field7=" + String(gWinddirectiondata) + "&field8=" + String(gHumidity);
  Serial.println(str);
  Serial3.println(str);//begin send data to remote server

  delay(4000);
  ShowSerialData();

  Serial3.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet
  Serial3.println();

  // Battery
   Serial3.println("AT+CIPSPRT=0");
  delay(3000);

  ShowSerialData();

  Serial3.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);

  ShowSerialData();
  Serial3.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();
  //  // Battery channel
  String strBat = "GET https://api.thingspeak.com/update?api_key=" + String(API_KEY_BATTERY) + "&field2=" + String(gIrradiance)+ "&field3=" + String(gPAR);
  Serial.println(strBat);
  Serial3.println(strBat);//begin send data to remote server

  delay(4000);
  ShowSerialData();

  Serial3.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet
  Serial3.println();

  ShowSerialData();

  Serial3.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
}
void ShowSerialData()
{
  while (Serial3.available() != 0)
    Serial.write(Serial3.read());
  delay(5000);

}
