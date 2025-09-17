#include <assert.h>
#include <cwctype>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "log.h"
#include "onegin_program.h"
#include "string_reader.h"

size_t take_string_number(wchar_t *buff);

void skip_new_line_chars(const wchar_t *buff, int *pos);

wchar_t *skip_new_line_chars_arr(wchar_t *buff);

int read_strings(FileData *onegin_data) {
  assert(onegin_data);

  wchar_t *buff = onegin_data->file_buf;
  const size_t buff_size = onegin_data->buf_size;

  LOG("detecting nubmer of strings");
  size_t strs_num = take_string_number(buff);

  if (strs_num == 1) {
    LOG_ERR("file has only 1 string");
    printf("Warning: file has only 1 string, programm will not be executed\n");
    return ONLY_ONE_STR;
  }

  LOG("starting string array creation");
  string_t *stroki = (string_t *)calloc(strs_num, sizeof(string_t));
  if (!stroki) {
    LOG_ERR("string array memory alocation error");
    return STR_ARR_MEM_ALC_ERR;
  }

  stroki[0].str_ptr = skip_new_line_chars_arr(buff);

  for (size_t str = 1; str < strs_num; str++) {
    wchar_t *new_line = wcschr(stroki[str - 1].str_ptr, '\0');

    stroki[str - 1].str_len = new_line - stroki[str - 1].str_ptr;
    stroki[str].str_ptr = skip_new_line_chars_arr(++new_line);
  }

  stroki[strs_num - 1].str_len =
      &buff[buff_size + 1] - stroki[strs_num - 1].str_ptr;

  LOG("string array created successfully");

  onegin_data->string_data = stroki;
  onegin_data->strings_data_size = strs_num;

  return 0;
}

size_t take_string_number(wchar_t *buff) {
  assert(buff);

  int pos = 0;
  size_t str_num = 0;

  skip_new_line_chars(buff, &pos);

  do {
    if (buff[pos] == '\n' || buff[pos] == '\r') {
      buff[pos++] = '\0';
      str_num++;

      skip_new_line_chars(buff, &pos);
    }
  } while (buff[pos++] != '\0');

  LOG("total number of strings is: %d", str_num);

  return str_num;
}

void skip_new_line_chars(const wchar_t *buff, int *pos) {
  assert(buff);
  assert(pos);

  while (iswspace((wint_t)buff[*pos]))
    (*pos)++;
}

wchar_t *skip_new_line_chars_arr(wchar_t *buff) {
  assert(buff);
  while (iswspace((wint_t)*buff))
    buff++;

  return buff;
}
