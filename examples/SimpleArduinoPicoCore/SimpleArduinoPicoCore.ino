#include "HyperDevice31I2CSlave.h"

// obtain unique id for "arduino-pico" core for RP2040 based boards
#include "hardware/flash.h"

// Initialize global Hyper device.
HyperDevice31I2CSlave hyperDevice;

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
    int lemna_sensor_density_adc_raw = analogRead(A0);
    Serial.print("lemna_sensor_density_adc_raw: ");
    Serial.println(lemna_sensor_density_adc_raw);

    // https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
    float lemna_sensor_density_volt = lemna_sensor_density_adc_raw * 5.0 / 1023.0;
    Serial.print("lemna_sensor_density_volt: ");
    Serial.println(lemna_sensor_density_volt);

    // Set the attribute value.
    hyperDevice.setFCAPLemnaSensorDensity_1(lemna_sensor_density_volt);

    int lemna_sensor_distance_adc_raw = analogRead(A1);
    Serial.print("lemna_sensor_distance_adc_raw: ");
    Serial.println(lemna_sensor_distance_adc_raw);

    float lemna_sensor_distance_volt = lemna_sensor_distance_adc_raw * 5.0 / 1023.0;
    Serial.print("lemna_sensor_distance_volt: ");
    Serial.println(lemna_sensor_distance_volt);

    // Set the attribute value.
    hyperDevice.setFCAPLemnaSensorDistance_1(lemna_sensor_distance_volt);

    delay(1000);
}
