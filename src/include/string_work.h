#ifndef ONEGIN_HEADER
#define ONEGIN_HEADER

enum ONEG_ERRS {
  ARGC_ERR = 1111,
  OUTPUT_OPN_ERR,
};

int str_cmp(const void *ptr1, const void *ptr2);

int reverse_str_cmp(const void *ptr1, const void *ptr2);

void string_print(FILE *out, string *strings, size_t str_number);

#endif
