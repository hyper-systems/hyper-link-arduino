#include "HyperDevice17I2CSlave.h"

// obtain unique id using ArduinoUniqueID library
// https://github.com/ricaun/ArduinoUniqueID
#include <ArduinoUniqueID.h>

// Initialize global Hyper device.
HyperDevice17I2CSlave hyperDevice;

void setup()
{
    Serial.begin(115200);

    // Begin the device with a unique identifier obtained using the last 
    // 6 bytes from UniqueID8 using the ArduinoUniqueID library
    hyperDevice.begin(&UniqueID8[2]);
}

void loop()
{
    int adcVal = analogRead(A0);
    Serial.print("Read ADC Value: ");
    Serial.println(adcVal);

    // Set the attribute value.
    hyperDevice.setTemperature1(adcVal);

    delay(1000);
}
