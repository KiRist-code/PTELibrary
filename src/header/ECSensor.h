#ifndef ECSensor_h
#define ECSensor_h

#include <OneWire.h>
#include "Arduino.h"

#define StartConvert 0
#define ReadTemperature 1

extern const byte numReadings = 20;

class EC{
    public:
        //arduino class basically set-up
        EC(byte EC_pin, byte DS18B20_pin);
        void setup();

        //personal set-up
        void initSensor();
        void EC_read();
        void DS18B20_read();
        float TempProcess(bool ch);

        //getter
        float getDSTemp();
        unsigned int getAnalogAverage();
        unsigned int getAverageVoltage();
        void setPrintTime();
        unsigned long getPrintTime();
        float getECcurrent();
        
    private:
        byte _EC_pin;
        byte _DS18D20_pin;
        byte customChar[8];
        float ECcurrent;
        unsigned int AnalogSampleInterval;
        unsigned long AnalogValueTotal;
        unsigned int AnalogAverage, averageVoltage;
        unsigned long AnalogSampleTime, printTime, tempSampleTime;
        unsigned int readings[numReadings];
        byte index;
        float temperature;
        unsigned int tempSampleInterval;
}

#endif