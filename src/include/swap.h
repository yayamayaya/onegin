#ifndef MEM_SWAP
#define MEM_SWAP

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>
#include <assert.h>
#include "../../../common/logging/log.h"

void mem_swap(void* first_ptr, void* second_ptr, int size);

#endif