#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>

const int ONEGIN_FILES_OPEN_ERR = 1111;

typedef struct files {
  char *input_file_name;
  FILE *output;
} OneginFiles;

OneginFiles parse_options(const int argc, char *const argv[]);

bool is_files_null(const OneginFiles *files);

void free_onegin_files(OneginFiles *files);

#endif
