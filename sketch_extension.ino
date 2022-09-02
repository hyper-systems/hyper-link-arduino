// HYPER: INCLUDES
#include "hyper_device_17_v3.gen.h"
#include "hyper_extension_bus.h"

// HYPER: Global device reference.
hyper_device_17_t hyper_device = {0};


// HYPER: Set up I2C set/get helpers.
static int hyper_extension_set_data(uint8_t *data, uint8_t data_len) {
  return 0;
}

static int hyper_extension_get_data(uint8_t *data, uint8_t *data_len) {
  hyper_result_t ret = hyper_device_17_encode(&hyper_device, data, data_len);
  if (ret != HYPER_OK) {
    Serial.println("hyper_device_17_encode failed.");
    return -1;
  } else {
    return 0;
  }
}


// The setup routine runs once when you press reset.
void setup() {
  // Initialize serial communication at 115200 bits per second.
  Serial.begin(115200);

  // HYPER: Initialize the device.
  uint8_t device_id[6] = {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01};
  hyper_device_17_init(&hyper_device, device_id);

  // HYPER: Setup I2C slave bus.
  hyper_extension_bus_slave_init(hyper_extension_get_data, hyper_extension_set_data);
}

void loop() {
  int adcVal = analogRead(A0);
  Serial.print("Read ADC Value: ");
  Serial.println(adcVal);

  hyper_device_17_set_temperature_1(&hyper_device, adcVal);

  delay(1000);
}
