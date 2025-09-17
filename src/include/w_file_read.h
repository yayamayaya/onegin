#ifndef W_FILE_READ
#define W_FILE_READ

#include <stdlib.h>

#include "onegin_program.h"

enum W_READ_ERRS {
  W_CHAR_READ_ERR = 111,
  WCHAR_MEM_ALC_ERR = 112,
  BYTE_READ_ERR = 113,
};

int w_file_read(FileData *onegin_data, const char *directory);

#endif
