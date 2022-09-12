#ifndef __HYPER_DEVICE_31_I2C_SLAVE__
#define __HYPER_DEVICE_31_I2C_SLAVE__

class HyperDevice31I2CSlave
{
public:
  HyperDevice31I2CSlave();

  void begin(const uint8_t id[6]);

  void setFCAPLemnaSensorDensity_1(float x);

  void setFCAPLemnaSensorDistance_1(float x);
};

#endif // __HYPER_DEVICE_31_I2C_SLAVE__
