#include "HyperDevice31I2CSlave.h"

// Initialize global Hyper device.
HyperDevice31I2CSlave hyperDevice;

void setup()
{
    Serial.begin(115200);

    // Begin the device with a unique identifier.
    const uint8_t deviceId[6] = {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01};
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
