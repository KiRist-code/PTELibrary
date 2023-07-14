#ifndef PTELib_h
#define PTELib_h

#include"Arduino.h"
#include"ECSensor.h"
#include"PHSensor.h"
#include"TempSensor.h"
#include <stdint.h>

class PTELib{
    public:
        PTELib(uint8_t phPin, uint8_t tempPin, uint8_t ecPin, uint8_t DS18D20Pin);
        void setup(int serial_port);
        void sensor_read();
    private:
        EC ec;
        PH ph;
        Temp temp;
        uint8_t _phPin;
        uint8_t _tempPin;
        uint8_t _ecPin;
        uint8_t _DS18D20Pin;
        unsigned long printTime;
        unsigned int printInterval;
};

#endif