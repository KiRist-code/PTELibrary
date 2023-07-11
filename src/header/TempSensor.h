#ifndef TempSensor_h
#define TempSensor_h

#include "Arduino.h"

class Temp{
    public:
        //arduino class basically set-up
        Temp(int pin);
        void setup();
        //personal set-up
        int temp_read();
    private:
        int _pin;
}

#endif