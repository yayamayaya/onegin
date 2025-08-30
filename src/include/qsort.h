#ifndef QSORT
#define QSORT

void quick_sort(void *arr, int arr_size, int type_size,
                int (*comparator)(const void *, const void *));

#endif
