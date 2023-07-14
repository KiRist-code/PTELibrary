#ifndef TempSensor_h
#define TempSensor_h

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class Temp{
    public:
        //arduino class basically set-up
        Temp(int pin);
        void begin();
        //personal set-up
        int temp_read();
    private:
        int _pin;
        OneWire ow;
        DallasTemperature t_Sensor;
};

#endif