#ifndef PHSensor_h
#define PHSensor_h

#include "Arduino.h"

class PH{
    public:
        //arduino class basically set-up
        PH(int pin);
        void setup();
        //personal set-up
        void PH_read();
        void averageAnalogRead();
        
    private:
        int _pin;
        float calibration;
        float pHValue;
        float pHVol;
        int buf[10];
        int temp;
}

#endif