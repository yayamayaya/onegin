#include "log.h"
#include "onegin_program.h"
#include "options.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int ret_val = 0;

  _OPEN_LOG("onegin.log");

  OneginFiles files = parse_options(argc, argv);
  if (is_files_null(&files))
    ret_val = ONEGIN_FILES_OPEN_ERR;
  else
    ret_val = run_onegin(&files);

  LOG("Programm completed");

  free_onegin_files(&files);
  _CLOSE_LOG();

  return ret_val;
}
