#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "bsort.h"
#include "log.h"
#include "qsort.h"
#include "string_reader.h"
#include "string_work.h"
#include "w_file_read.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("> number of arguments does not match needed (write input and "
           "output files)\n");
    return ARGC_ERR;
  }

  _OPEN_LOG("onegin.log");
  wchar_t *buff = NULL;
  size_t size = 0;

  setlocale(LC_ALL, "ru_RU.UTF-8");

  LOG("locale is set, starting file-reading");
  int error = w_file_read(&buff, &size, argv[2]);
  if (error) {
    _CLOSE_LOG();
    return error;
  }

  LOG("file was read");

  int string_number = 0;
  string_t *strs = NULL;
  error = read_strings(&strs, &string_number, buff, size);
  if (error) {
    _CLOSE_LOG();
    return error;
  }

  LOG("opening output file");
  FILE *out = fopen(argv[1], "w");
  if (!out) {
    LOG_ERR("couldn't open output file");
    free(buff);
    free(strs);
    _CLOSE_LOG();
    return OUTPUT_OPN_ERR;
  }

  LOG("sorting in alphabet order");
  fwprintf(out, L"#sorting text in alphabet order:\n\n");
  quick_sort(strs, string_number, sizeof(string_t), str_cmp);
  string_print(out, strs, string_number);

  LOG("sorting in reverse alphabet order");
  fwprintf(out, L"\n#sorting in alphabet order from the end:\n\n");
  quick_sort(strs, string_number, sizeof(string_t), reverse_str_cmp);
  string_print(out, strs, string_number);

  LOG("programm completed");

  fclose(out);
  free(strs);
  free(buff);
  _CLOSE_LOG();

  return 0;
}
