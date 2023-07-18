#include "PHSensor.h"
#include "Arduino.h"

void PH::begin(uint8_t pin)
{
    this->_pin = pin;
    this->calibration = 37.62;
}

void PH::PH_read()
{
    averageAnalogRead();

    pHVol = ((float)avgValue * 5.0 / 1024 / 6) - 0.08;
    pHValue = -9.457 * pHVol + calibration;

    // displayLCD();
}

void PH::averageAnalogRead()
{
    for (int i = 0; i < 9; i++)
    {
        buf[i] = analogRead(_pin);
        delay(30);
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (buf[i] > buf[j])
            {
                temp = buf[i];
                buf[i] = buf[j];
                buf[j] = temp;
            }
        }
    }

    avgValue = 0;

    for (int i = 2; i < 8; i++)
    {
        avgValue += buf[i];
    }
}

float PH::getPHValue()
{
    return pHValue;
}

float PH::getPHVol()
{
    return pHVol;
}