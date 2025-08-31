#include <assert.h>
#include <cwctype>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "log.h"
#include "string_reader.h"

size_t take_string_number(wchar_t *buff);

int read_strings(string_t **strs, size_t *string_number, wchar_t *buff,
                 const size_t buff_size) {
  assert(strs);
  assert(string_number);
  assert(buff);

  LOG("detecting nubmer of strings");
  size_t strs_num = take_string_number(buff);

  if (strs_num == 1) {
    LOG_ERR("file has only 1 string");
    printf("Warning: file has only 1 string, programm will not be executed\n");
    free(buff);
    return ONLY_ONE_STR;
  }

  LOG("starting string array creation");
  string_t *stroki = (string_t *)calloc(strs_num, sizeof(string_t));
  if (!stroki) {
    LOG_ERR("string array memory alocation error");
    free(buff);
    return STR_ARR_MEM_ALC_ERR;
  }

  stroki[0].str_ptr = buff;
  for (size_t str = 1; str < strs_num; str++) {
    // fix string start
    stroki[str].str_ptr = wcschr(stroki[str - 1].str_ptr, '\0') + 1;
    // fix string length
    stroki[str - 1].str_len = stroki[str].str_ptr - stroki[str - 1].str_ptr;

    if (*stroki[str].str_ptr == '\n')
      stroki[str].str_ptr += 1;
  }
  stroki[strs_num - 1].str_len =
      &buff[buff_size + 1] - stroki[strs_num - 1].str_ptr;

  LOG("string array created successfully");

  *strs = stroki;
  if (string_number)
    *string_number = strs_num;

  return 0;
}

size_t take_string_number(wchar_t *buff) {
  assert(buff);

  int pos = 0;
  size_t str_num = 0;
  while (buff[pos] != '\0') {
    if (buff[pos] == '\n' || buff[pos] == '\r') {
      buff[pos] = '\0';
      str_num++;

      while (iswspace((wint_t)buff[++pos]))
        ;
    } else {
      pos++;
    }
  }

  LOG("total number of strings is: %d", str_num);

  return str_num;
}
