#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

// #include "bsort.h"
#include "log.h"
#include "onegin_program.h"
#include "qsort.h"
#include "string_reader.h"
#include "string_work.h"
#include "w_file_read.h"

void sort_text(FILE *out, string *strs, const size_t string_number);

int run_onegin(const OneginFiles *files) {
  assert(files);

  FileData file_data = {NULL, 0, NULL, 0};
  int ret_val = 0;

  setlocale(LC_ALL, "ru_RU.UTF-8");

  LOG("locale is set, starting file-reading");
  ret_val = w_file_read(&file_data, files->input_file_name);
  if (ret_val)
    goto finish;

  LOG("parsing file into strings");
  ret_val = read_strings(&file_data);
  if (ret_val)
    goto finish;

  sort_text(files->output, file_data.string_data, file_data.strings_data_size);

finish:
  free(file_data.file_buf);
  free(file_data.string_data);

  return ret_val;
}

void sort_text(FILE *out, string_t *strs, const size_t string_number) {
  assert(out);
  assert(strs);

  LOG("sorting in alphabet order");
  fwprintf(out,
           L"-------------------------------------------------------------"
           L"----------------------\n"
           L"-------------------------Sorting text in alphabet "
           L"order----------------------------\n"
           L"--------------------------------------------------------------"
           L"---------------------\n");
  quick_sort(strs, (int)string_number, sizeof(string_t), str_cmp);
  string_print(out, strs, string_number);

  LOG("sorting in reverse alphabet order");
  fwprintf(out,
           L"------------------------------------------------------------------"
           L"-----------------\n"
           L"---------------------Sorting text in alphabet from end of "
           L"the----------------------\n"
           L"--------------------------------------------------------------"
           L"---------------------\n");
  quick_sort(strs, (int)string_number, sizeof(string_t), reverse_str_cmp);
  string_print(out, strs, string_number);
}
