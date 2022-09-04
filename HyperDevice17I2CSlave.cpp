
#include "hyper_device_17_v3.gen.h"
#include "hyper_device_core_v3.h"
#include "hyper_extension_bus.h"

#include "HyperDevice17I2CSlave.h"


static hyper_device_17_t _device = {0};

/*
  Decode device data and dispatch attributes.

  Return:
  - `0` on success;
  - `-1` if the decoding of data as device fails.
 */
static int hyper_device_17_set_data(
    uint8_t *data,
    uint8_t len
  ) {
  hyper_result_t res = hyper_device_17_decode(
    &_device,
    data,
    len
  );
  if (res != HYPER_OK) {
    return -1;
  }

  uint8_t _dispatched_count =
    hyper_device_17_dispatch(&_device);

  return 0;
}

/*
  Encode device data.

  Return:
  - `0` on success;
  - `-1` if the encoding of the device fails.
 */
static int hyper_device_17_get_data(
    uint8_t *data,
    uint8_t *len
  ) {
  hyper_result_t ret = hyper_device_17_encode(
    &_device,
    data,
    len
  );
  if (ret != HYPER_OK) {
    return -1;
  }

  return 0;
}


HyperDevice17I2CSlave::HyperDevice17I2CSlave() { }


void HyperDevice17I2CSlave::begin(const uint8_t id[6]) {
  hyper_device_17_init(&_device, (uint8_t *)id);
  hyper_extension_bus_slave_init(hyper_device_17_get_data, hyper_device_17_set_data);
}


void HyperDevice17I2CSlave::setTemperature1(float x) {
  hyper_device_17_set_temperature_1(&_device, x);
}

