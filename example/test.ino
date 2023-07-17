#include "PTELib.h"

PTELib PTELib(A1, 10, A2, 10);

void setup()
{
    PTELib.begin(9600);
}

void loop()
{
    PTELib.sensor_read();
}