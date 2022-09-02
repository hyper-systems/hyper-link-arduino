#include <Arduino.h>
#include <Wire.h>

#include "hyper_extension_bus.h"


#if defined(ARDUINO_ARCH_AVR)
TwoWire HyperExtensionBus = TwoWire();
#elif defined(ARDUINO_ARCH_MBED_RP2040) || defined(ARDUINO_ARCH_RP2040)
#define HyperExtensionBus Wire
#else
TwoWire HyperExtensionBus = TwoWire(HYPER_EXTENSION_BUS_I2C_SLAVE_SDA_PIN, HYPER_EXTENSION_BUS_I2C_SLAVE_SCL_PIN);
#endif

volatile uint8_t reg_addr_ptr = 0;
volatile uint8_t i2c_reg[HYPER_EXTENSION_DATA_REG_START_ADDR + HYPER_EXTENSION_DATA_MAX_SIZE] = {0};

int (*hyper_extension_get_data)(uint8_t *data, uint8_t *data_len);
int (*hyper_extension_set_data)(uint8_t *data, uint8_t data_len);

// reset function, should force watchdog to kick in
void (*soft_reboot)(void);

void receiveEvent(int rx_bytes)
{
  int available_bytes = HyperExtensionBus.available();

  if (rx_bytes != available_bytes)
  {
    Serial.println("error: rx_bytes != available_bytes \n");
    // reset
    soft_reboot();
    return;
  }

  reg_addr_ptr = HyperExtensionBus.read();

  // check if read command
  if (rx_bytes > 1)
  {
    uint8_t write_reg_addr_ptr = reg_addr_ptr;
    // TODO: forbid writing in certain registers
    while (HyperExtensionBus.available())
    {
      i2c_reg[write_reg_addr_ptr] = HyperExtensionBus.read();
      write_reg_addr_ptr++;
    }
    if (reg_addr_ptr == HYPER_EXTENSION_BUS_CONTROL_REG_ADDR)
    {
      if (i2c_reg[HYPER_EXTENSION_BUS_CONTROL_REG_ADDR] == HYPER_EXTENSION_BUS_CMD_GET_DATA)
      {
        int ret = hyper_extension_get_data(
            (uint8_t *)&i2c_reg[HYPER_EXTENSION_DATA_REG_START_ADDR],
            (uint8_t *)&i2c_reg[HYPER_EXTENSION_BUS_DATA_SIZE_REG_ADDR]);
        // set return code in HYPER_EXTENSION_BUS_CONTROL_REG_ADDR
        i2c_reg[HYPER_EXTENSION_BUS_CONTROL_REG_ADDR] = ret;
        if (ret != 0)
        {
          Serial.println("error: hyper_extension_get_data failed");
          return;
        }
      }
      else if (i2c_reg[HYPER_EXTENSION_BUS_CONTROL_REG_ADDR] == HYPER_EXTENSION_BUS_CMD_SET_DATA)
      {
        if (i2c_reg[HYPER_EXTENSION_BUS_DATA_SIZE_REG_ADDR] > 0)
        {
          int ret = hyper_extension_set_data(
              (uint8_t *)&i2c_reg[HYPER_EXTENSION_DATA_REG_START_ADDR],
              (uint8_t)i2c_reg[HYPER_EXTENSION_BUS_DATA_SIZE_REG_ADDR]);
          // set return code in HYPER_EXTENSION_BUS_CONTROL_REG_ADDR
          i2c_reg[HYPER_EXTENSION_BUS_CONTROL_REG_ADDR] = ret;
          if (ret != 0)
          {
            Serial.println("error: hyper_extension_set_data failed");
            return;
          }
        }
        else
        {
          Serial.println("error: HYPER_EXTENSION_BUS_CMD_SET_DATA but HYPER_EXTENSION_BUS_DATA_SIZE_REG_ADDR is 0!");
          return;
        }
      }
      return;
    }
  }
}

void requestEvent()
{
  // fill the buffer with the maximum number of bytes
  uint8_t write_len = 32;
  if ((sizeof(i2c_reg) - reg_addr_ptr) < 32)
  {
    write_len = sizeof(i2c_reg) - reg_addr_ptr;
  }
  HyperExtensionBus.write((uint8_t *)&i2c_reg[reg_addr_ptr], write_len);
}

void hyper_extension_bus_slave_init(
    int (*get_data)(uint8_t *data, uint8_t *data_len),
    int (*set_data)(uint8_t *data, uint8_t data_len)
) {
  hyper_extension_get_data = get_data;
  hyper_extension_set_data = set_data;

  // init reserved regs
  memset((uint8_t *)i2c_reg, 0xFF, HYPER_EXTENSION_DATA_REG_START_ADDR);

  HyperExtensionBus.begin(0x5);
  // Function to run when data requested from master
  HyperExtensionBus.onRequest(requestEvent);
  // Function to run when data received from master
  HyperExtensionBus.onReceive(receiveEvent);
}
