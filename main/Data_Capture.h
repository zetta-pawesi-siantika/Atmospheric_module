/*Variables that contain data from each sensor*/ 

#ifndef DATA_CAPTURE_H
#define DATA_CAPTURE_H


/* Anemo meter sensor data */
float gWindspeed = 0; 

/* BME280 */
byte gTemperature;
float gPressure;
float gHumidity;

/* Rain Sensor */
int gRaindata; 

/* BH1750 */
float gLux;
float gIrradiance;
float gPAR;

/* Uv Sensor */
float gUvindex;

/* Wind direction */
int gWinddirectiondata;

/* Time DS3231 */
 String dateNow; 
 String timeNow;

 byte hourNow;
 byte minuteNow;
 
#endif
