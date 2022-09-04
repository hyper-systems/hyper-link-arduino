#ifndef __HYPER_DEVICE_17_I2C_SLAVE__
#define __HYPER_DEVICE_17_I2C_SLAVE__

class HyperDevice17I2CSlave {
public:
  HyperDevice17I2CSlave();

  void begin(const uint8_t id[6]);

  void setTemperature1(float x);
};

#endif // __HYPER_DEVICE_17_I2C_SLAVE__
