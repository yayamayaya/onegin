#include "include/swap.h"
#include <stdint.h>
#include <stdio.h>

void bsort(void *arr_ptr, int arr_size, int type_size,
           int (*comparator)(const void *, const void *)) {
  for (int pass = 0; pass < arrSize - 1; pass++)
    for (int i = 0; i < arrSize - pass - 1; i++)
      if (comparator((uint8_t *)arrPoint + i * typeSize,
                     (uint8_t *)arrPoint + (i + 1) * typeSize) > 0)
        mem_swap(((uint8_t *)arrPoint + i * typeSize),
                 ((uint8_t *)arrPoint + (i + 1) * typeSize), typeSize);
}
