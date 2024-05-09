#ifndef STR_READ
#define STR_READ

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "wchar.h"
#include "../../../common/logging/log.h"

typedef struct string {
    wchar_t *str_ptr;
    int str_len;
} string_t;

enum STR_READ_ERRS
{
    ONLY_ONE_STR = 1818,
};

int read_strings(string_t **strs, int *string_number, wchar_t *buff, const int buff_size);

#endif