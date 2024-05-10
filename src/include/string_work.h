#ifndef ONEGIN_HEADER
#define ONEGIN_HEADER

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include "string_reader.h"
#include "w_file_read.h"

enum ONEG_ERRS
{
    ARGC_ERR = 1111,
    OUTPUT_OPN_ERR,
};

int str_cmp(const void *ptr1, const void *ptr2);
int reverse_str_cmp(const void *ptr1, const void *ptr2);
void string_print(FILE *out, string* strings, int str_number);

#endif