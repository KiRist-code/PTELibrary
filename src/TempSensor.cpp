#include"TempSensor.h"
#include"Arduino.h"

Temp::Temp(int pin) {
    _pin = pin;
}

void Temp::begin(){
    OneWire ourWire(_pin);
    sensor.begin();
}

int Temp::temp_read(){
    sensors.reqeustTemperatures();
    return sensors.getTempCByIndex(0);
    //displayLCD();
}
