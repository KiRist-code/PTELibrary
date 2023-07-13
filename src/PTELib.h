#ifndef PTELib_h
#define PTELib_h

#include"Arduino.h"
#include"ECSensor.h"
#include"PHSensor.h"
#include"TempSensor.h"

class PTELib{
    public:
        PTELib(int phPin, int tempPin, byte ecPin, byte DS18D20Pin);
        void setup(int serial_port);
        void sensor_read();
    private:
        EC ec;
        PH ph;
        Temp temp;
        int _phPin;
        int _tempPin;
        byte _ecPin;
        byte _DS18D20Pin;
        unsigned long printTime;
        unsigned int printInterval;
};

#endif