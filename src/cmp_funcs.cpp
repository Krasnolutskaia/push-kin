#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmp_funcs.h"
 

int compare_strs(const void * str1, const void * str2)
{
    return strcmp(*(const char **)str1, *(const char **)str2);
}


int find_min(void *data, int count, int size, int (*comp)(const void *, const void *))
{
    int min_index = 0;
    for (int i = 1; i < count; i++)
    {
        if (comp(data + i * size, data + min_index * size) < 0)
        {
            min_index = i;
        }
    }
    return min_index;
}


static void swap(void* v1, void* v2, int size)
{
    char * buffer = (char *) calloc(size, sizeof(char));

    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}


void selection_sort(void *data, int count, int size, int (*comp)(const void *, const void *))
{
    for (int i = 0; i < count; i++)
    {
        swap(data + size * i, data + size * (find_min(data + i * size, count - i, size, comp) + i), size);
    }
}
