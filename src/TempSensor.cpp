#include"TempSensor.h"
#include"Arduino.h"

Temp::Temp(int pin) {
    _pin = pin;
    ow = OneWire(_pin);
    t_Sensor = DallasTemperature(&ow);
}

void Temp::begin(){
    t_Sensor.begin();
}

int Temp::temp_read(){
    t_Sensor.reqeustTemperatures();
    return t_Sensor.getTempCByIndex(0);
    //displayLCD();
}
