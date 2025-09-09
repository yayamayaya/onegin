#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>

typedef struct files {
  const char *input_file_name;
  FILE *output;
} OneginFiles;

OneginFiles parse_options(const int argc, const char *argv[]);

bool is_files_null(const OneginFiles *files);

void free_onegin_files(OneginFiles *files);

#endif
