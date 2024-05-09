#ifndef W_FILE_READ
#define W_FILE_READ

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
#include "../../../common/logging/log.h"
#include "../../../common/file_reading/src/file_reading.h"

enum CHAR_SIZE
{
    TWO_BYTES   = 0xC0,
    THREE_BYTES = 0xE0,
    FOUR_BYTES  = 0xF0
};

enum W_READ_ERRS
{
    W_CHAR_READ_ERR = 111,
};

int w_file_read(wchar_t **arr_ptr, int *w_file_size, const char *directory);

#endif