#ifndef W_FILE_READ
#define W_FILE_READ

enum W_READ_ERRS {
  W_CHAR_READ_ERR = 111,
  WCHAR_MEM_ALC_ERR = 112,
  BYTE_READ_ERR = 113,
};

int w_file_read(wchar_t **arr_ptr, size_t *w_file_size, const char *directory);

#endif
