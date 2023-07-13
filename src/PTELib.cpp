#include"Arduino.h"
#include"PTELib.h"

PTELib::PTELib(int phPin, int tempPin, byte ecPin, byte DS18D20Pin){
    _phPin = phPin;
    _tempPin = tempPin;
    _ecPin = ecPin;
    _DS18D20Pin = DS18D20Pin;
    printInterval = 700;

    ec = EC(_ecPin, _DS18D20Pin);
    temp = Temp(_tempPin);
    ph = PH(_phPin);
}

void PTELib::setup(int serial_port){
    ec.setup();
    printTime = ec.getPrintTime();
    temp.setup();

    Seiral.begin(serial_port);
}

void PTELib::sensor_read(){
    //read EC sensor
    ec.EC_read();
    ec.DS18B20_read();
    //read temperature sensor
    int temperature = temp.temp_read();
    //read PH sensor
    ph.PH_read();

    /*Serial Display*/

    //EC
    unsigned int analogAverage = ec.getAnalogAverage();
    if(millis() - printTime >= printInterval){
        ec.setPrintTime();
        printTime = ec.getPrintTime();
        unsigned int averageVoltage = ec.getAverageVoltage();

        Serial.print("Analog value: ");
        Serial.print(analogAverage);
        Serial.print("      Voltage: ");
        Serial.print(averageVoltage);
        Serial.print("mv    EC: ");
        
        float currentEC = ec.getECcurrent();
        switch((int)currentEC){
            case -1:
                Serial.print("No Solution");
                break;
            case -2:
                Serial.print("Out of Range");
                break;
            default:
                Serial.print(currentEC, 2);
                Serial.print("ms/cm");
                break;
        }
    }

    //PH
    float pHValue = ph.getPHValue();
    float pHVol = ph.getPHVol();
    Serial.print("Vol: ");
    Serial.println(pHValue);
    Serial.print("ph: ");
    Serial.println(pHVol);

    //temperature
    Serial.print("Temperature: ");
    Serial.println(temperature);
}
