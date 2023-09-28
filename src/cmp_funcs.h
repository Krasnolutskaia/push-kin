#ifndef CMP_FUNCS_H_
#define CMP_FUNCS_H_
#include <stdio.h>

int compare_strs(const void * str1, const void * str2);

int find_min(void *data, int count, int size, int (*comp)(const void *, const void *));

void selection_sort(void *data, int count, int size, int (*comp)(const void *, const void *));

#endif
