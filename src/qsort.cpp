#include "swap.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "qsort.h"

void quick_sort(void *arr, int arr_size, int type_size,
                int (*comparator)(const void *, const void *)) {
  if (arr_size == 1 || arr_size == 0)
    return;

  if (comparator((uint8_t *)arr, (uint8_t *)arr + type_size) > 0)
    mem_swap((uint8_t *)arr, (uint8_t *)arr + type_size, type_size);

  int cmp = 0;
  int first_pos = cmp + 1;
  int second_pos = arr_size - 1;

  while (first_pos + second_pos < 2 * arr_size) {
    while (first_pos != second_pos &&
           comparator((uint8_t *)arr + cmp * type_size,
                      (uint8_t *)arr + first_pos * type_size) > 0)
      first_pos++;

    while (first_pos != second_pos &&
           comparator((uint8_t *)arr + cmp * type_size,
                      (uint8_t *)arr + second_pos * type_size) <= 0)
      second_pos--;

    if (first_pos == second_pos)
      break;

    mem_swap((uint8_t *)arr + first_pos * type_size,
             (uint8_t *)arr + second_pos * type_size, type_size);
    first_pos++;
  }

  mem_swap((uint8_t *)arr + cmp * type_size,
           (uint8_t *)arr + (first_pos - 1) * type_size, type_size);
  cmp = first_pos - 1;

  quick_sort(arr, cmp, type_size, comparator);
  quick_sort((uint8_t *)arr + first_pos * type_size, arr_size - cmp - 1,
             type_size, comparator);
  return;
}
