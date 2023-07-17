#ifndef ECSensor_h
#define ECSensor_h

#include <OneWire.h>
#include "Arduino.h"
#include <stdint.h>

#define StartConvert 0
#define ReadTemperature 1

class EC
{
public:
    // arduino class basically set-up
    EC() {}
    EC(uint8_t EC_pin, uint8_t DS18B20_pin) { begin(EC_pin, DS18B20_pin); };
    void begin(uint8_t EC_pin, uint8_t DS18B20_pin);

    // personal set-up
    void initSensor();
    void EC_read();
    void DS18B20_read();
    float TempProcess(bool ch);

    // getter
    float getDSTemp();
    unsigned int getAnalogAverage();
    unsigned int getAverageVoltage();
    void setPrintTime();
    unsigned long getPrintTime();
    float getECcurrent();

private:
    uint8_t _EC_pin;
    uint8_t _DS18D20_pin;
    byte customChar[8];
    float ECcurrent;
    unsigned int AnalogSampleInterval;
    unsigned long AnalogValueTotal;
    unsigned int AnalogAverage, averageVoltage;
    unsigned long AnalogSampleTime, printTime, tempSampleTime;
    unsigned int readings[20];
    byte index;
    float temperature;
    unsigned int tempSampleInterval;
    byte numReadings;
    OneWire ds;
};

#endif