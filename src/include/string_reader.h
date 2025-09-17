#ifndef STR_READ
#define STR_READ

#include "onegin_program.h"

enum STR_READ_ERRS {
  ONLY_ONE_STR = 1818,
  STR_ARR_MEM_ALC_ERR = 1819,
};

int read_strings(FileData *onegin_file);

#endif
