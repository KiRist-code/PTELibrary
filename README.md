# PTELibrary

</p>
    <p align="center">
        <a href="https://github.com/KiRist-code/PTELibrary/graphs/contributors" alt="Contributors">
            <img src="https://img.shields.io/github/contributors/badges/shields" /></a>
        <a href="https://github.com/KiRist-code/PTELibrary/pulse" alt="Activity">
            <img src="https://img.shields.io/github/commit-activity/m/badges/shields" /></a>
    </p>
</p>

Check PH, Temperature, Electrical Conductivity at one time.
This library project use OneWire, DallasTemperature to control SKU-DFR0300, PH4502C, DS18B20.
Only can use Arduino UNO.

## Installation

Before the Installation, we need to download "Git" & "OneWire", "DallasTemperature" Library

### Git Install

[git_install](https://git-scm.com/downloads)

Download the appropriate program for the OS.

### OneWire & DallasTemperature Install

Sketch -> Include Library -> Manage Libraries -> Search "OneWire" & "DallasTemperature" -> Install

### Git clone

```bash

git clone https://github.com/KiRist-code/PTELibrary.git

```

### Pack the Library as ZIP

1. copy the all files in src folder and make folder named "PTELib"
2. make "PTELib" folder as ZIP
3. Back to the Arduino IDE and go to Sketch -> Include Library -> Add .ZIP Library
4. include the "PTELib.zip"

## Usage

Use this Library like this code.

```ino
#include "PTELib.h"

/*
PTELib function have to 4 arguments
phPin number, tempPin number, ecPin number, DS18D20Pin number
*/

PTELib PTELib(A1, 10, A2, 10);

void setup()
{
    //Serial port
    PTELib.begin(9600);
}

void loop()
{
    //read Sensor value & print to Seiral
    PTELib.sensor_read();
}
```

## Contributing

PTELibrary Project is for all Arduino users. All participants for issues and pull request are welcome!

There is no template for issue & pull request yet. If you are interested in making these template, it would be so grateful.
