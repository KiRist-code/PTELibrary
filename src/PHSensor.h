#ifndef PHSensor_h
#define PHSensor_h

#include "Arduino.h"

class PH
{
public:
    // arduino class basically set-up
    PH() {}
    PH(uint8_t pin) { begin(pin); };
    void begin(uint8_t pin);
    // personal set-up
    void PH_read();
    void averageAnalogRead();
    float getPHValue();
    float getPHVol();

private:
    int _pin;
    float calibration;
    float pHValue;
    float pHVol;
    int buf[10];
    int temp;
    unsigned long int avgValue;
};

#endif