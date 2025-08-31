#ifndef BSORT
#define BSORT

#include <stdint.h>
#include <stdlib.h>

void bsort(void *arr_ptr, int arr_size, int type_size,
           int (*comparator)(const void *, const void *));

#endif
