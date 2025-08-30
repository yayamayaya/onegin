#include <stdint.h>

#include "bsort.h"
#include "swap.h"
#include <stdint.h>
#include <stdio.h>

void bsort(void *arr_ptr, int arr_size, int type_size,
           int (*comparator)(const void *, const void *)) {
  for (int pass = 0; pass < arr_size - 1; pass++)
    for (int i = 0; i < arr_size - pass - 1; i++)
      if (comparator((uint8_t *)arr_ptr + i * type_size,
                     (uint8_t *)arr_ptr + (i + 1) * type_size) > 0)
        mem_swap(((uint8_t *)arr_ptr + i * type_size),
                 ((uint8_t *)arr_ptr + (i + 1) * type_size), type_size);
}
