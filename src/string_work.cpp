#include "include/string_work.h"

int str_cmp(void *ptr1, void *ptr2)
{
    assert(ptr1);
    assert(ptr2);

    string_t *str1 = (string_t *)ptr1;
    string_t *str2 = (string_t *)ptr2;

    int pos = 0;

    while (str1->str_ptr[pos] == str2->str_ptr[pos] && str1->str_ptr[pos] != '\0')
        pos++;

    return str1->str_ptr[pos] - str2->str_ptr[pos];
}

int reverse_str_cmp(void *ptr1, void *ptr2)
{
    assert(ptr1);
    assert(ptr2);

    string_t *str1 = (string_t *)ptr1;
    string_t *str2 = (string_t *)ptr2;

    int pos1 = str1->str_len - 2;
    int pos2 = str2->str_len - 2;

    while (!iswalpha(str1->str_ptr[pos1]) && pos1 > 0)
        pos1--;
    
    while (!iswalpha(str2->str_ptr[pos2]) && pos2 > 0)
        pos2--;

    while (str1->str_ptr[pos1] == str2->str_ptr[pos2] && pos1 > 0 && pos2 > 0)
    {
        pos1--;
        pos2--;
    }

    return str1->str_ptr[pos1] - str2->str_ptr[pos2];
}

void string_print(FILE *out, string* strings, int str_number)
{
    for (int i = 0; i < str_number; i++)
        fwprintf(out, L"%ls\n", strings[i]);
}