#include "HyperDevice17I2CSlave.h"

// Initialize global Hyper device.
HyperDevice17I2CSlave hyperDevice;

void setup()
{
    Serial.begin(115200);

    // Begin the device with a unique identifier.
    const uint8_t deviceId[6] = {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01};
    hyperDevice.begin(deviceId);
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
