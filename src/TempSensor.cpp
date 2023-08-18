#include "TempSensor.h"
#include "Arduino.h"

void Temp::begin(uint8_t pin)
{
    this->_pin = pin;
    this->ow = OneWire(_pin);
    this->t_Sensor = DallasTemperature(&ow);

    t_Sensor.begin();
}

int Temp::temp_read()
{
    t_Sensor.requestTemperatures();
    return t_Sensor.getTempCByIndex(0);
    // displayLCD();
}
