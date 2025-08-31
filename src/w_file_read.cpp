#include <assert.h>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "file_reading.h"
#include "log.h"
#include "w_file_read.h"

enum CharSizes {
  ONE_BYTE = 0x00,
  TWO_BYTES = 0x80,
  THREE_BYTES = 0xE0,
  FOUR_BYTES = 0xF0
};

size_t get_w_file_size(char *buff, const size_t file_size);

int w_file_read(wchar_t **arr_ptr, size_t *w_file_size, const char *directory) {
  assert(arr_ptr);
  assert(directory);
  assert(w_file_size);

  char *buff = NULL;
  size_t file_size = 0;

  LOG("reading file into a buffer");
  int error = file_read(&buff, &file_size, directory);
  if (error) {
    LOG_ERR("file reading error");
    return error;
  }

  LOG("size of wchar: %ld", sizeof(wchar_t));
  LOG("detecting wide buff size");
  size_t wide_file_size = get_w_file_size(buff, file_size);
  if (wide_file_size == (size_t)-1) {
    free(buff);
    return BYTE_READ_ERR;
  }

  LOG("allocating memory for wchar buffer");
  wchar_t *wbuff = (wchar_t *)calloc(wide_file_size + 1, sizeof(wchar_t));
  if (!wbuff) {
    LOG("wide char memory allocation error");
    free(buff);
    return WCHAR_MEM_ALC_ERR;
  }

  if (mbstowcs(wbuff, buff, file_size) == (size_t)-1) {
    LOG("wide char reading error");
    free(buff);
    free(wbuff);
    return W_CHAR_READ_ERR;
  }

  if (w_file_size)
    *w_file_size = wide_file_size;

  *arr_ptr = wbuff;

  free(buff);
  return 0;
}

size_t get_w_file_size(char *buff, const size_t file_size) {
  assert(buff);

  size_t wide_buff_size = 0;

  for (size_t pos = 0; pos < file_size;) {
    switch (buff[pos] & 0xF0) {
    case FOUR_BYTES:
      pos += 4;
      break;

    case THREE_BYTES:
      pos += 3;
      break;

    default:
      break;
    }

    switch (buff[pos] & 0x80) {
    case TWO_BYTES:
      pos += 2;
      break;

    case ONE_BYTE:
      pos++;
      break;

    default:
      LOG("Critical error: couldn't understand a character in "
          "file, please check your encoding to be UTF-8");
      return (size_t)-1;
    }

    wide_buff_size++;
  }

  LOG("wide char buffer size: %d", wide_buff_size);
  return wide_buff_size;
}
