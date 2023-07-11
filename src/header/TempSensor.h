#ifndef TempSensor_h
#define TempSensor_h

#include "Arduino.h"

class Temp{
    public:
        //arduino class basically set-up
        Temp(int pin);
        void setup();
        //personal set-up
        void Temp_read();
        void averageAnalogRead();
        
    private:
        int _pin;
        int buf[10];
}

#endif