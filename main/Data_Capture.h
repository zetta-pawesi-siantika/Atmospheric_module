/*Variables that contain data from each sensor*/ 

#ifndef DATA_CAPTURE_H
#define DATA_CAPTURE_H


/* Anemo meter sensor data */
float gWindspeed = 0; 

/* BME280 */
float gTemperature;
float gPressure;
float gHumidity;

/* MQ135 */
float gCo;
float gAlcohol;
float gCo2;
float gTolueno;
float gNh4;
float gAcetona;

/* Rain Sensor */
int gRaindata; 

/* Temt6000_Sensor */
int gTemt6000data;

/* Uv Sensor */
byte gUvdata;

/* Wind direction */
String gWinddirectiondata;
 
#endif
