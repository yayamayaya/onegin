#ifndef BSORT
#define BSORT

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "swap.h"

void bsort(void* arr_ptr, int arr_size, int type_size, int (*comparator)(const void*, const void*));

#endif