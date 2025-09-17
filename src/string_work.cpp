#include <assert.h>
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>

#include "onegin_program.h"
#include "string_work.h"

int str_cmp(const void *ptr1, const void *ptr2) {
  assert(ptr1);
  assert(ptr2);

  const string_t *str1 = (const string_t *)ptr1;
  const string_t *str2 = (const string_t *)ptr2;

  int pos = 0;

  while (str1->str_ptr[pos] == str2->str_ptr[pos] &&
         str1->str_ptr[pos] != '\0' && str2->str_ptr[pos] != '\0') {
    pos++;
  }

  return str1->str_ptr[pos] - str2->str_ptr[pos];
}

int reverse_str_cmp(const void *ptr1, const void *ptr2) {
  assert(ptr1);
  assert(ptr2);

  const string_t *str1 = (const string_t *)ptr1;
  const string_t *str2 = (const string_t *)ptr2;

  long int pos1 = str1->str_len - 1;
  long int pos2 = str2->str_len - 1;

  while (!iswalpha((wint_t)str1->str_ptr[pos1]) && pos1 > 0)
    pos1--;

  while (!iswalpha((wint_t)str2->str_ptr[pos2]) && pos2 > 0)
    pos2--;

  while (str1->str_ptr[pos1] == str2->str_ptr[pos2] && pos1 > 0 && pos2 > 0) {
    pos1--;
    pos2--;
  }

  return str1->str_ptr[pos1] - str2->str_ptr[pos2];
}

void string_print(FILE *out, string_t *strings, size_t str_number) {
  for (size_t i = 0; i < str_number; i++)
    fwprintf(out, L"%ls\n", strings[i]);
}
