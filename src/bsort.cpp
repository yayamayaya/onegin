#include <stdio.h>
#include <stdint.h>
#include "include/swap.h"

void bsort(void* arr_ptr, int arr_size, int type_size, int (*comparator)(void*, void*))
{
    for (int pass = 0; pass < arrSize - 1; pass++)
        for (int i = 0; i < arrSize - pass - 1; i++)
            if (Comparator((uint8_t *)arrPoint + i * typeSize, (uint8_t *)arrPoint + (i + 1) * typeSize) > 0)  
                SwapOpt(((uint8_t *)arrPoint + i * typeSize), ((uint8_t *)arrPoint + (i + 1) * typeSize), typeSize);         
}