#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmp_funcs.h"
 

int str_cmp(const void * str1, const void * str2)
{
    return strcmp(*(const char **)str1, *(const char **)str2);
}


int str_cmp_letters(const void * elem1, const void * elem2)
{
    const char* str1 = *(const char **) elem1;
    const char* str2 = *(const char **) elem2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;
    int j = 0;
    
    while (i <= len1 && j <= len2)
    {
        if (isalpha(str1[i]) != 0 && isalpha(str2[j]) != 0)
        {
            if (str1[i] != str2[j]) 
            {
            return str1[i] - str2[j];
            }
            i++;
            j++;
            continue;
        }

        if (isalpha(str1[i]) == 0)
        {
            i++;
        }
        if (isalpha(str2[j]) == 0)
        {
            j++;
        }
    }

    return str1[i] - str2[j];
}


int reverse_str_cmp(const void * elem1, const void * elem2)
{
    const char* str1 = *(const char **) elem1;
    const char* str2 = *(const char **) elem2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = len1 - 1;
    int j = len2 - 1;
    
    while (i >= 0 && j >= 0)
    {
        if (str1[i] != str2[j]) 
        {
            return str1[i] - str2[j];
        }
        i--;
        j--;
    }
    return str1[i] - str2[j];
}


int reverse_str_cmp_letters(const void * elem1, const void * elem2)
{
    const char* str1 = *(const char **) elem1;
    const char* str2 = *(const char **) elem2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = len1 - 1;
    int j = len2 - 1;

    while (i >= 0 && j >= 0)
    {
        if (isalpha(str1[i]) != 0 && isalpha(str2[j]) != 0)
        {
            if (str1[i] != str2[j]) 
            {
            return str1[i] - str2[j];
            }
            i--;
            j--;
            continue;
        }

        if (isalpha(str1[i]) == 0)
        {
            i--;
        }
        if (isalpha(str2[j]) == 0)
        {
            j--;
        }
    }

    return str1[i] - str2[j];
}


int find_min_index(void *data, int count, int size, int (*comp)(const void *, const void *))
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
    if (buffer == NULL)
    {
        printf("no memory\n");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}


void selection_sort(void *data, int count, int size, int (*comp)(const void *, const void *))
{
    for (int i = 0; i < count; i++)
    {
        swap(data + size * i, data + size * (find_min_index(data + i * size, count - i, size, comp) + i), size);
    }
}
