/* Anemometer sensor properties */
// it produces wind speed value
// src: https://www.instructables.com/How-to-Use-a-Adafruit-Anemometer-Sensor-With-Ardui/

// bugs
#define ANEMOMETERPIN A5 // -> #issue1: it has to put pin definition here. IO_Mapping doesnt work here 

// variables global
float gWindspeed = 0; // Wind speed in meters per second (m/s)


// private Variables
float _anesensorVoltage = 0; //Variable that stores the voltage (in Volts) from the anemometer being sent to the analog pin
int _anesensorValue = 0; //Variable stores the value direct from the analog pin
float _anevoltageConversionConstant = .004882814; //This constant maps the value provided from the analog read function, which ranges from 0 to 1023, to actual voltage, which ranges from 0V to 5V
int _anesensorDelay = 1000; //Delay between sensor readings, measured in milliseconds (ms)

//Anemometer Technical Variables
//The following variables correspond to the anemometer sold by Adafruit, but could be modified to fit other anemometers.
float _anevoltageMin = .4; // Mininum output voltage from anemometer in mV.
float _anewindSpeedMin = 0; // Wind speed in meters/sec corresponding to minimum voltage
float _anevoltageMax = 2.0; // Maximum output voltage from anemometer in mV.
float _anewindSpeedMax = 32; // Wind speed in meters/sec corresponding to maximum voltage


// setup method
void setupAnemosensor() {
  pinMode(ANEMOMETERPIN, INPUT);

}

void readAnemosensor() {
  _anesensorValue = analogRead(ANEMOMETERPIN); //Get a value between 0 and 1023 from the analog pin connected to the anemometer
  _anesensorVoltage = _anesensorValue * _anevoltageConversionConstant; //Convert sensor value to actual voltage

  //Convert voltage value to wind speed using range of max and min voltages and wind speed for the anemometer
  if (_anesensorVoltage <= _anevoltageMin) {
    gWindspeed = 0; //Check if voltage is below minimum value. If so, set wind speed to zero.
  } else {
    gWindspeed = (_anesensorVoltage - _anevoltageMin) * _anewindSpeedMax / (_anevoltageMax - _anevoltageMin); //For voltages above minimum value, use the linear relationship to calculate wind speed.
  }

  /*Serial Debug */
  #ifdef DEBUG_ANEMO
    Serial.print("Voltage: ");
    Serial.print(_anesensorVoltage);
    Serial.print("\t");
    Serial.print("Wind speed: ");
    Serial.println(gWindspeed);
  #endif

}
