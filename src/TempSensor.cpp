#include"TempSensor.h"
#include"Arduino.h"

Temp::Temp(int pin) {
    _pin = pin;
}

void Temp::setup(){
    sensor.begin();
}

int Temp::temp_read(){
    sensors.reqeustTemperatures();
    return sensors.getTempCByIndex(0);
    //displayLCD();
}
