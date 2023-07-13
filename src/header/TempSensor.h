#ifndef TempSensor_h
#define TempSensor_h

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class Temp{
    public:
        //arduino class basically set-up
        Temp(int pin);
        void setup();
        //personal set-up
        int temp_read();
    private:
        int _pin;
        OneWire ourWire(_pin);
        DallasTemperature sensors(&ourWire);
};

#endif