#ifndef QSORT
#define QSORT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "swap.h"

void quick_sort(void *arr, int arr_size, int type_size, int (*comparator)(const void*, const void*));

#endif