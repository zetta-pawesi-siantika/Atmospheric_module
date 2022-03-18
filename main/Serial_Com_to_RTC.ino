// MEGA

void setupSerialRTCoperation() {
  // put your setup code here, to run once:
  Serial2.begin(9600);

}

void serialRTCoperation() {
  // put your main code here, to run repeatedly:

  // sending "OK" (Module wakes up)
  sendDataserial("OK");

  // waiting ..
    delay(5000);
    
  // recieving rainfall data and store data to g variable 
  if(Serial2.available() > 0){
    gCurahhujan = recieveData();
  }    
}


String recieveData(){
  String readString;
  String Q;
  
 while (Serial2.available()) {
      delay(1);
    if (Serial2.available() >0) {
      char c = Serial2.read();  //gets one byte from serial buffer
    if (isControl(c)) {
      //'Serial.println("it's a control character");
      break;
    }
      readString += c; //makes the string readString    
    }
 }   
 
 Q = readString;
 return Q;

 Serial.println(Q);
 delay(1000);
}

void sendDataserial(String _data){
  Serial2.print(_data);
  Serial2.flush();
}
