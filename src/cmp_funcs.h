#ifndef CMP_FUNCS_H_
#define CMP_FUNCS_H_
#include <stdio.h>

int str_cmp(const void * str1, const void * str2);

int find_min_index(void *data, int count, int size, int (*comp)(const void *, const void *));

int reverse_str_cmp(const void * elem1, const void * elem2);

void selection_sort(void *data, int count, int size, int (*comp)(const void *, const void *));

int str_cmp_letters(const void * elem1, const void * elem2);

int reverse_str_cmp_letters(const void * elem1, const void * elem2);

#endif