#include "HyperDevice17I2CSlave.h"

// obtain unique id for "arduino-pico" core for RP2040 based boards
#include "hardware/flash.h"

// Initialize global Hyper device.
HyperDevice17I2CSlave hyperDevice;

void setup()
{
    Serial.begin(115200);

    // Begin the device with a unique identifier obtained using `flash_get_unique_id`
    uint8_t deviceId[6];
    flash_get_unique_id(deviceId);

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
