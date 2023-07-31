#include "Arduino.h"
#include "PTELib.h"

PTELib::PTELib(uint8_t phPin, uint8_t tempPin, uint8_t ecPin, uint8_t DS18D20Pin)
{
    this->_phPin = phPin;
    this->_tempPin = tempPin;
    this->_ecPin = ecPin;
    this->_DS18D20Pin = DS18D20Pin;
    this->printInterval = 700;

    this->ec = EC(_ecPin, _DS18D20Pin); // pinMode 세팅 완료
    this->temp = Temp(_tempPin);        // pinMode 세팅 완료
    this->ph = PH(_phPin);
}

void PTELib::begin(int serial_port)
{
    // ec.begin();
    printTime = ec.getPrintTime();
    // temp.begin();

    Serial.begin(serial_port);
}

void PTELib::sensor_read()
{
    // read EC sensor
    ec.EC_read();
    ec.DS18B20_read();
    // read temperature sensor
    int temperature = temp.temp_read();
    // read PH sensor
    ph.PH_read();

    /*Serial Display*/

    // PH
    float pHValue = ph.getPHValue();
    float pHVol = ph.getPHVol();
    Serial.print(",");
    Serial.println(pHValue);
    // Serial.print(",");
    // Serial.println(pHVol);

    // temperature
    Serial.print(",");
    Serial.println(temperature);

    // EC
    unsigned int analogAverage = ec.getAnalogAverage();
    if (millis() - printTime >= printInterval)
    {
        ec.setPrintTime();
        printTime = ec.getPrintTime();
        unsigned int averageVoltage = ec.getAverageVoltage();

        // Serial.println("CLEARDATA");
        // Serial.println("LABEL, Analog Value, Voltage, EC, PH, Temp");

        // Serial.print("DATA,");
        // Serial.print(analogAverage);
        // Serial.print(",");
        // Serial.print(averageVoltage);
        // Serial.print(",");

        float currentEC = ec.getECcurrent();
        switch ((int)currentEC)
        {
        case -1:
            Serial.println("No Solution");
            break;
        case -2:
            Serial.println("Out of Range");
            break;
        default:
            Serial.print(currentEC, 2);
            break;
        }
    }
}
