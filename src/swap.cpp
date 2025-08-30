#include <assert.h>
#include <memory.h>
#include <stdint.h>
#include <stdlib.h>

#include "log.h"
#include "swap.h"

void mem_dump(void *ptr, int size);

void mem_swap(void *first_ptr, void *second_ptr, int size) {
  uint64_t temp = 0;
  int pos = 0;

#ifdef FULL_DUMP
  LOG("swapping memory of size: %d", size);
  mem_dump(first_ptr, size);
  mem_dump(second_ptr, size);
  LOG("----------------------------------------------------------------------");
#endif

  while (size >> 3) {
    memcpy(&temp, ((uint8_t *)first_ptr + pos), sizeof(uint64_t));
    memcpy(((uint8_t *)first_ptr + pos), ((uint8_t *)second_ptr + pos),
           sizeof(uint64_t));
    memcpy(((uint8_t *)second_ptr + pos), &temp, sizeof(uint64_t));
    pos += 8;
    size -= 8;
  }
  if (size & 0x04) {
    memcpy(&temp, ((uint8_t *)first_ptr + pos), sizeof(uint32_t));
    memcpy(((uint8_t *)first_ptr + pos), ((uint8_t *)second_ptr + pos),
           sizeof(uint32_t));
    memcpy(((uint8_t *)second_ptr + pos), &temp, sizeof(uint32_t));
    pos += 4;
  }
  if (size & 0x02) {
    memcpy(&temp, ((uint8_t *)first_ptr + pos), sizeof(uint16_t));
    memcpy(((uint8_t *)first_ptr + pos), ((uint8_t *)second_ptr + pos),
           sizeof(uint16_t));
    memcpy(((uint8_t *)second_ptr + pos), &temp, sizeof(uint16_t));
    pos += 2;
  }
  if (size & 0x01) {
    memcpy(&temp, ((uint8_t *)first_ptr + pos), sizeof(uint8_t));
    memcpy(((uint8_t *)first_ptr + pos), ((uint8_t *)second_ptr + pos),
           sizeof(uint8_t));
    memcpy(((uint8_t *)second_ptr + pos), &temp, sizeof(uint8_t));
  }
}

void mem_dump(void *ptr, int size) {
  LOG("0b");

  for (int i = 0; i < size; i++) {
    uint8_t byte = *((uint8_t *)ptr + i);
    for (int j = 0; j < 8; j++) {
      LOG("%c", (byte & 0x80) ? '1' : '0');
      byte <<= 1;
    }
    LOG(" ");
  }

  LOG("\n");
}
