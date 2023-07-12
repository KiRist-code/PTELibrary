#include"ECSensor.h"
#include"Arduino.h"

EC::EC(byte EC_pin, byte DS18B20_pin){
    _EC_pin = EC_pin;
    _DS18B20_pin = DS18B20_pin;
    AnalogSampleInterval = 25;
    AnalogValueTotal = 0;
    AnalogAverage = 0;
    averageVoltage = 0;
    index = 0;
    tempSampleInterval = 850;
    printInterval = 700;
    customChar = {B11000,B11000,B00111,B01000,B01000,B01000,B00111,B00000};

    OneWire ds(_DS18B20_pin);
}

EC::setup() {
    //initLCD();
    EC::initSensor();
}

EC::initSensor(){
    for(byte thisReading = 0;thisReading < numReadings; thisReading++){
        readings[thisReading] = 0;
    }

    TempProcess(startConvert);
    
    AnalogSampleTime = millis();
    printTime = millis();
    tempSampleTime = millis();
}

EC::EC_read() {
    if(millis() - AnalogSampleTime >= AnalogSampleInterval){
        AnalogSampleTime = millis();
        AnalogValueTotal = AnalogValueTotal - reading[index];
        readings[index] = analogRead(_EC_Pin);
        AnalogValueTotal = AnalogValueTotal + readings[index];
        index = index + 1;

        if(index >= numReadings){
            index = 0;
        }

        AnalogAverage = AnalogValueTotal / numReadings;
    }
}

EC::DS18B20_read(){
    
}