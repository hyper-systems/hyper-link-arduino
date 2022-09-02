// --- HYPER GENERATED CODE %VERSION% 1645202745 ---
//
// WARNING
//
// This file was automatically generated by the Hyper Platform.
// Manual changes MUST NOT be made, consult documentation at hyper.ag for more
// information.

#ifndef __HYPER_DEVICE_CLASS_17__
#define __HYPER_DEVICE_CLASS_17__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cmp.h"

#include "hyper_device_core_v3.h"

// --- DEVICE TYPE ---
typedef struct {
  uint8_t version;
  uint32_t device_class_id;
  uint8_t device_id[6];
  

  uint8_t temperature_1_set : 1;
  float temperature_1;
  uint8_t temperature_2_set : 1;
  float temperature_2;
  uint8_t temperature_3_set : 1;
  float temperature_3;
  uint8_t temperature_4_set : 1;
  float temperature_4;
  
} hyper_device_17_t;

void hyper_device_17_reset(hyper_device_17_t * device) {
  device->temperature_1_set = 0;
  device->temperature_1 = 0.0;
  device->temperature_2_set = 0;
  device->temperature_2 = 0.0;
  device->temperature_3_set = 0;
  device->temperature_3 = 0.0;
  device->temperature_4_set = 0;
  device->temperature_4 = 0.0;
}


void hyper_device_17_init(hyper_device_17_t * device, uint8_t device_id[6]) {
  device->version = 3;
  device->device_class_id = 17;
  memcpy(device->device_id, device_id, 6);
  hyper_device_17_reset(device);
}


// --- PRINT DEVICE ---
void hyper_device_17_print(hyper_device_17_t * device) {
  HYPER_PRINTF(
    "(hyper_device_17_t\n"
    "  (version %d)\n"
    "  (device_class_id %lu)\n"
    "  (device_id (%02x %02x %02x %02x %02x %02x))\n",
    device->version, (long unsigned)device->device_class_id, device->device_id[0],
    device->device_id[1], device->device_id[2], device->device_id[3],
    device->device_id[4], device->device_id[5]);
      

  if (device->temperature_1_set) {
    HYPER_PRINTF("  (temperature_1 (f32 %f))\n", device->temperature_1);
  } else {
    HYPER_PRINTF("  (temperature_1 (f32 none))\n");
  }

  if (device->temperature_2_set) {
    HYPER_PRINTF("  (temperature_2 (f32 %f))\n", device->temperature_2);
  } else {
    HYPER_PRINTF("  (temperature_2 (f32 none))\n");
  }

  if (device->temperature_3_set) {
    HYPER_PRINTF("  (temperature_3 (f32 %f))\n", device->temperature_3);
  } else {
    HYPER_PRINTF("  (temperature_3 (f32 none))\n");
  }

  if (device->temperature_4_set) {
    HYPER_PRINTF("  (temperature_4 (f32 %f))\n", device->temperature_4);
  } else {
    HYPER_PRINTF("  (temperature_4 (f32 none))\n");
  }
  HYPER_PRINTF(")\n");
}


// --- BIND ATTRIBUTES ---

// --- SET ATTRIBUTES ---
void hyper_device_17_set_temperature_1(hyper_device_17_t * device, float value) {
  device->temperature_1_set = 1;
  device->temperature_1 = value;
}


void hyper_device_17_set_temperature_2(hyper_device_17_t * device, float value) {
  device->temperature_2_set = 1;
  device->temperature_2 = value;
}


void hyper_device_17_set_temperature_3(hyper_device_17_t * device, float value) {
  device->temperature_3_set = 1;
  device->temperature_3 = value;
}


void hyper_device_17_set_temperature_4(hyper_device_17_t * device, float value) {
  device->temperature_4_set = 1;
  device->temperature_4 = value;
}


// --- ENCODE DEVICE ---
hyper_result_t hyper_device_17_encode(hyper_device_17_t * device, uint8_t * out, uint8_t * out_len) {
  cmp_ctx_t cmp_ctx = {0};
  hyper_msgpack_buffer_t msgpack_buf = {out, 0};

  cmp_init(&cmp_ctx, (void *)&msgpack_buf, NULL, NULL, hyper_device_msgpack_writer);

  // Encode message as array of elements.
  if (!cmp_write_array(&cmp_ctx, 3)) {
    HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
    return HYPER_ERR_ENCODE;
  }
         
  // Device info.
  if (!cmp_write_uinteger(&cmp_ctx, device->device_class_id)) {
    HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
    return HYPER_ERR_ENCODE;
  }

  if (!cmp_write_bin(&cmp_ctx, device->device_id, 6)) {
    HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
    return HYPER_ERR_ENCODE;
  }

  uint8_t defined_attributes_count = 0;
  if (device->temperature_1_set) ++defined_attributes_count;
  if (device->temperature_2_set) ++defined_attributes_count;
  if (device->temperature_3_set) ++defined_attributes_count;
  if (device->temperature_4_set) ++defined_attributes_count;

  // Attributes
  if (!cmp_write_map(&cmp_ctx, defined_attributes_count)) {
    HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
    return HYPER_ERR_ENCODE;
  }

  // 0: temperature_1
  if (device->temperature_1_set) {
    if (!cmp_write_u8(&cmp_ctx, 0)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
    if (!cmp_write_float(&cmp_ctx, device->temperature_1)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
  }

  // 1: temperature_2
  if (device->temperature_2_set) {
    if (!cmp_write_u8(&cmp_ctx, 1)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
    if (!cmp_write_float(&cmp_ctx, device->temperature_2)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
  }

  // 2: temperature_3
  if (device->temperature_3_set) {
    if (!cmp_write_u8(&cmp_ctx, 2)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
    if (!cmp_write_float(&cmp_ctx, device->temperature_3)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
  }

  // 3: temperature_4
  if (device->temperature_4_set) {
    if (!cmp_write_u8(&cmp_ctx, 3)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
    if (!cmp_write_float(&cmp_ctx, device->temperature_4)) {
      HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
      return HYPER_ERR_ENCODE;
    }
  }

  *out_len = msgpack_buf.offset;
  return HYPER_OK;
}


// --- DECODE DEVICE ---
hyper_result_t hyper_device_17_decode(hyper_device_17_t * device, uint8_t * in, uint8_t in_size) {
  cmp_ctx_t cmp_ctx = {0};
  hyper_msgpack_buffer_t msgpack_buf = {in, 0};

  cmp_init(&cmp_ctx, (void *)&msgpack_buf, hyper_device_msgpack_reader, NULL, NULL);
      
  uint32_t msg_array_size = 0;

  // Main msg array
  if (!cmp_read_array(&cmp_ctx, &msg_array_size) && msg_array_size != 3) {
    HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
    return HYPER_ERR_DECODE;
  }

  cmp_object_t obj;

  // Device class id
  if (!cmp_read_object(&cmp_ctx, &obj)) {
    HYPER_PRINTF("%s\n", "could not read object");
    return HYPER_ERR_DECODE;
  }
  if (!cmp_object_as_uint(&obj, &device->device_class_id)) {
    HYPER_PRINTF("%s\n", "could not read device_class_id\n");
    return HYPER_ERR_DECODE;
  }

  // Device id
  uint32_t device_id_size = 0;
  if (!cmp_read_bin_size(&cmp_ctx, &device_id_size)) {
    HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
    return HYPER_ERR_DECODE;
  }

  if (device_id_size != 6) {
    HYPER_PRINTF("%s\n", "hyper_device_decode: wrong device_id_size\n");
    return HYPER_ERR_DECODE;
  }

  memcpy(device->device_id, in + msgpack_buf.offset, 6);
  msgpack_buf.offset += 6;

  // Attributes
  uint32_t attributes_map_len = 0;
  if (!cmp_read_map(&cmp_ctx, &attributes_map_len)) {
    HYPER_PRINTF("%s\n", cmp_strerror(&cmp_ctx));
    return HYPER_ERR_DECODE;
  }

  uint8_t key = 0xFF;
  for (uint16_t i = 0; i < attributes_map_len; ++i) {
    // Key
    if (!cmp_read_object(&cmp_ctx, &obj)) {
      HYPER_PRINTF("%s\n", "could not read map key");
      return HYPER_ERR_DECODE;
    }
    if (cmp_object_as_uchar(&obj, &key)) {
      // Value
      if (!cmp_read_object(&cmp_ctx, &obj)) {
        HYPER_PRINTF("%s\n", "could not read attribute value");
        return HYPER_ERR_DECODE;
      }
      switch (key) {
      case 0: // temperature_1
        if (cmp_object_as_float(&obj, &device->temperature_1)) {
          device->temperature_1_set = 1; 
        } else {
          HYPER_PRINTF("%s\n", "could not read value\n");
            return HYPER_ERR_DECODE;
        }
        break;

      case 1: // temperature_2
        if (cmp_object_as_float(&obj, &device->temperature_2)) {
          device->temperature_2_set = 1; 
        } else {
          HYPER_PRINTF("%s\n", "could not read value\n");
            return HYPER_ERR_DECODE;
        }
        break;

      case 2: // temperature_3
        if (cmp_object_as_float(&obj, &device->temperature_3)) {
          device->temperature_3_set = 1; 
        } else {
          HYPER_PRINTF("%s\n", "could not read value\n");
            return HYPER_ERR_DECODE;
        }
        break;

      case 3: // temperature_4
        if (cmp_object_as_float(&obj, &device->temperature_4)) {
          device->temperature_4_set = 1; 
        } else {
          HYPER_PRINTF("%s\n", "could not read value\n");
            return HYPER_ERR_DECODE;
        }
        break;

      default:
        HYPER_PRINTF("%s\n", "attribute index out of bounds\n");
        return HYPER_ERR_DECODE;
      }
    } else {
      HYPER_PRINTF("%s\n", "could not read value\n");
      return HYPER_ERR_DECODE;
    }
  }
  return HYPER_OK;
}


// --- DISPATCH DEVICE ---
uint8_t hyper_device_17_dispatch(hyper_device_17_t * device) {
  uint8_t count = 0;

  return count;
}


#ifdef __cplusplus
}
#endif

#endif // __HYPER_DEVICE_CLASS_17__
