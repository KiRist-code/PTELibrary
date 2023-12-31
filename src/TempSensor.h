#ifndef TempSensor_h
#define TempSensor_h

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <stdint.h>

class Temp
{
public:
    // arduino class basically set-up
    Temp(){}
    Temp(uint8_t pin) { begin(pin); };
    void begin(uint8_t pin);
    // personal set-up
    int temp_read();

private:
    int _pin;
    OneWire ow;
    DallasTemperature t_Sensor;
};

#endif