#include"TempSensor.h"
#include"Arduino.h"

Temp::Temp(int pin) {
    _pin = pin;
    ow = ourWire(_pin);
    t_Sensor = sensors(&ourWire);
}

void Temp::setup(){
    t_Sensor.begin();
}

int Temp::temp_read(){
    t_Sensors.reqeustTemperatures();
    return sensors.getTempCByIndex(0);
    //displayLCD();
}
