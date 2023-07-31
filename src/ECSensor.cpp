#include "ECSensor.h"
#include "Arduino.h"

void EC::begin(uint8_t EC_pin, uint8_t DS18B20_pin)
{
    this->_EC_pin = EC_pin;
    this->_DS18D20_pin = DS18B20_pin;
    this->AnalogSampleInterval = 25;
    this->AnalogValueTotal = 0;
    this->AnalogAverage = 0;
    this->averageVoltage = 0;
    this->index = 0;
    this->tempSampleInterval = 850;
    this->numReadings = 20;

    byte inputCustomChar[] = {B11000, B11000, B00111, B01000, B01000, B01000, B00111, B00000};

    for (int i = 0; i < 8; i++)
    {
        this->customChar[i] = inputCustomChar[i];
    }

    this->ds = OneWire(_DS18D20_pin);

    // initLCD();
    EC::initSensor();
}

void EC::initSensor()
{
    for (byte thisReading = 0; thisReading < numReadings; thisReading++)
    {
        readings[thisReading] = 0;
    }

    // TempProcess(StartConvert);

    AnalogSampleTime = millis();
    setPrintTime();
    tempSampleTime = millis();
}

void EC::EC_read()
{
    if (millis() - AnalogSampleTime >= AnalogSampleInterval)
    {
        AnalogSampleTime = millis();
        AnalogValueTotal = AnalogValueTotal - readings[index];
        readings[index] = analogRead(_EC_pin);
        AnalogValueTotal = AnalogValueTotal + readings[index];
        index = index + 1;

        if (index >= numReadings)
        {
            index = 0;
        }

        AnalogAverage = AnalogValueTotal / numReadings;
    }
}

// void EC::DS18B20_read()
// {
//     if (millis() - tempSampleTime >= tempSampleInterval)
//     {
//         tempSampleTime = millis();
//         temperature = TempProcess(ReadTemperature);
//         TempProcess(StartConvert);
//     }
// }

// float EC::TempProcess(bool ch)
// {
//     static byte data[12];
//     static byte addr[8];
//     static float TemperatureSum;

//     if (!ch)
//     {
//         if (!ds.search(addr))
//         {
//             Serial.println("no more sensors on chain, reset search!");
//             ds.reset_search();
//             return 0;
//         }

//         if (OneWire::crc8(addr, 7) != addr[7])
//         {
//             Serial.println("CRC is not vaild!");
//             return 0;
//         }

//         if (addr[0] != 0x10 && addr[0] != 0x28)
//         {
//             Serial.print("Device is not recognized!");
//             return 0;
//         }

//         ds.reset();
//         ds.select(addr);
//         ds.write(0x44, 1);
//     }
//     else
//     {
//         byte present = ds.reset();
//         ds.select(addr);
//         ds.write(0xBE);

//         for (int i = 0; i < 9; i++)
//         {
//             data[i] = ds.read();
//         }

//         ds.reset_search();
//         byte MSB = data[1];
//         byte LSB = data[0];
//         float tempRead = ((MSB << 8) | LSB);

//         TemperatureSum = tempRead / 16;
//     }
//     return TemperatureSum;
// }

// getter
float EC::getDSTemp()
{
    return temperature;
}

unsigned int EC::getAnalogAverage()
{
    return AnalogAverage;
}

unsigned int EC::getAverageVoltage()
{
    averageVoltage = AnalogAverage * (float)5000 / 1024;
    return averageVoltage;
}

unsigned long EC::getPrintTime()
{
    return printTime;
}

void EC::setPrintTime()
{
    printTime = millis();
}

float EC::getECcurrent()
{
    float TempCoefficient = 1.0 + 0.0185 * (temperature - 25.0);
    float CoefficientVoltage = (float)averageVoltage / TempCoefficient;

    if (CoefficientVoltage < 150)
    {
        return -1; // No Solution
    }
    else if (CoefficientVoltage > 3300)
    {
        return -2; // Out of Range
    }
    else
    {
        if (CoefficientVoltage <= 448)
        {
            ECcurrent = 6.84 * CoefficientVoltage - 64.32;
        }
        else if (CoefficientVoltage <= 1457)
        {
            ECcurrent = 6.98 * CoefficientVoltage - 127;
        }
        else
        {
            ECcurrent = 5.3 * CoefficientVoltage + 2278;
        }

        ECcurrent /= 1000;
        return ECcurrent;
    }
}