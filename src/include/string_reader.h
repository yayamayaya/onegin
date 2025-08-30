#ifndef STR_READ
#define STR_READ

typedef struct string {
  wchar_t *str_ptr;
  long int str_len;
} string_t;

enum STR_READ_ERRS {
  ONLY_ONE_STR = 1818,
  STR_ARR_MEM_ALC_ERR = 1819,
};

int read_strings(string_t **strs, size_t *string_number, wchar_t *buff,
                 const size_t buff_size);

#endif
