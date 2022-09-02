#ifndef HYPER_EXTENSION_BUS_H
#define HYPER_EXTENSION_BUS_H

#define HYPER_EXTENSION_DATA_MAX_SIZE 128

typedef enum
{
    HYPER_EXTENSION_RES_ERROR = 0x00,
    HYPER_EXTENSION_RES_ERROR_NOT_READY,
} hyper_extension_control_reg_result_t;

typedef enum
{
    HYPER_EXTENSION_BUS_CMD_GET_DATA = 0x01,
    HYPER_EXTENSION_BUS_CMD_SET_DATA = 0x02,
} hyper_extension_cmds_t;

#define HYPER_EXTENSION_BUS_CONTROL_REG_ADDR 0x01
#define HYPER_EXTENSION_BUS_DATA_SIZE_REG_ADDR 0x02
#define HYPER_EXTENSION_DATA_REG_START_ADDR 0x0A

void hyper_extension_bus_slave_init(
    int (*get_data)(uint8_t *data, uint8_t *data_len),
    int (*set_data)(uint8_t *data, uint8_t data_len)
);

#endif // HYPER_EXTENSION_BUS_H
