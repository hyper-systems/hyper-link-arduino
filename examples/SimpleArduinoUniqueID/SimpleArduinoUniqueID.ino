#include "HyperDevice31I2CSlave.h"

// obtain unique id using ArduinoUniqueID library
// https://github.com/ricaun/ArduinoUniqueID
#include <ArduinoUniqueID.h>

// Initialize global Hyper device.
HyperDevice31I2CSlave hyperDevice;

void setup()
{
    Serial.begin(115200);

    // Begin the device with a unique identifier obtained using the last 
    // 6 bytes from UniqueID8 using the ArduinoUniqueID library
    hyperDevice.begin(&UniqueID8[2]);
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
