
#include "hyper_device_31_v3.gen.h"
#include "hyper_device_core_v3.h"
#include "hyper_extension_bus.h"

#include "HyperDevice31I2CSlave.h"


static hyper_device_31_t _device = {0};

/*
  Decode device data and dispatch attributes.

  Return:
  - `0` on success;
  - `-1` if the decoding of data as device fails.
 */
static int hyper_device_31_set_data(
    uint8_t *data,
    uint8_t len
  ) {
  hyper_result_t res = hyper_device_31_decode(
    &_device,
    data,
    len
  );
  if (res != HYPER_OK) {
    return -1;
  }

  uint8_t _dispatched_count =
    hyper_device_31_dispatch(&_device);

  return 0;
}

/*
  Encode device data.

  Return:
  - `0` on success;
  - `-1` if the encoding of the device fails.
 */
static int hyper_device_31_get_data(
    uint8_t *data,
    uint8_t *len
  ) {
  hyper_result_t ret = hyper_device_31_encode(
    &_device,
    data,
    len
  );
  if (ret != HYPER_OK) {
    return -1;
  }

  return 0;
}


HyperDevice31I2CSlave::HyperDevice31I2CSlave() { }


void HyperDevice31I2CSlave::begin(const uint8_t id[6]) {
  hyper_device_31_init(&_device, (uint8_t *)id);
  hyper_extension_bus_slave_init(hyper_device_31_get_data, hyper_device_31_set_data);
}


void HyperDevice31I2CSlave::setFCAPLemnaSensorDensity_1(float x) {
  hyper_device_31_set_fcap_lemna_density_0_1(&_device, x);
}

void HyperDevice31I2CSlave::setFCAPLemnaSensorDistance_1(float x) {
  hyper_device_31_set_fcap_lemna_sensor_distance_0_1(&_device, x);
}
