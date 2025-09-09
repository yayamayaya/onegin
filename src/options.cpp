#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "options.h"

void print_help_message();

char *copy_string(const char *str);

OneginFiles parse_options(const int argc, const char *argv[]) {
  OneginFiles res = {NULL, NULL};

  const struct option longopts[] = {
      {"help", no_argument, NULL, 'h'},
      {"input", required_argument, NULL, 'i'},
      {"output", required_argument, NULL, 'o'},
  };

  LOG("Parsing onegin options");
  int opt = 0;
  while ((opt = getopt_long(argc, argv, "hi:o:", longopts, NULL)) != -1) {
    switch (opt) {

    case '?':
      printf("Unknown argument, please rewind arguments");
      LOG_ERR("Unknown argument error");
      [[fallthrough]];
    case 'h':
      print_help_message();
      exit(0);

    case 'i':
      res.input_file_name = copy_string(optarg);
      if (!res.input_file_name)
        LOG_ERR("Error while copying a string: %s", strerror(errno));

      break;

    case 'o':
      res.output = fopen(optarg, "wb");
      if (!res.output) {
        LOG_ERR("Error while opening an output file: %s", strerror(errno));
        printf("Couldn't open output file: %s\n", strerror(errno));

        return res;
      }
      break;

    default:
      LOG_ERR("FATAL: default case shouldn't been reached");
      exit(1);
    }
  }

  if (res.output == NULL) {
    LOG("No output file given, writing to stdout");
    res.output = stdout;
  }
}

char *copy_string(const char *str) {
  size_t string_len = strlen(str);

  char *copy = (char *)calloc(string_len + 1, sizeof(char));
  if (!copy)
    return NULL;

  return strcpy(copy, str);
}

void print_help_message() {
  printf("Onegin will sort your text in alphabetical of strings start and "
         "strings end\n");

  printf("Usage:\n");
  printf("--help, -h: show this message\n");
  printf("--input, -i: pass input file\n");
  printf("--output, -o: pass output file\n");

  printf("If output file is not set, the result will be printed in stdout\n");
}

bool is_files_null(const OneginFiles *files) {
  return !(files->input_file_name && files->output);
}

void free_onegin_files(OneginFiles *files) {
  if (files->input_file_name) {
    free(files->input_file_name);
  }

  if (files->output) {
    fclose(files->output);
  }
}
