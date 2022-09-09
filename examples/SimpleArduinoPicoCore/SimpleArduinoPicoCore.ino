#include "HyperDevice17I2CSlave.h"

// obtain unique id for "arduino-pico" core for RP2040 based boards
#include "hardware/flash.h"

// Initialize global Hyper device.
HyperDevice17I2CSlave hyperDevice;

void setup()
{
    Serial.begin(115200);

    // get the RP2040 64bit unique id
    uint8_t rp2040_unique_id[8];
    flash_get_unique_id(rp2040_unique_id);

    // get the last 6 bytes from the previously obtained 64bit unique id
    uint8_t deviceId[6];
    memcpy(deviceId, &rp2040_unique_id[2], 6);

    // Begin the device with the 48 bit (6 bytes) unique identifier obtained previously
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
