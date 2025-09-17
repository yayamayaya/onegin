#ifndef ONEGIN_PROJECT_H_
#define ONEGIN_PROJECT_H_

#include "options.h"

typedef struct string {
  wchar_t *str_ptr;
  long int str_len;
} string_t;

typedef struct FileDataSt {
  wchar_t *file_buf;
  size_t buf_size;
  string_t *string_data;
  size_t strings_data_size;
} FileData;

int run_onegin(const OneginFiles *files);

#endif
