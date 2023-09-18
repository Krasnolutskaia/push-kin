#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utilities.h"


char * my_strdup(const char* s1)
{
    int size = strlen(s1);
    char *s2 = (char *) calloc(size + 1, sizeof(char));
    strcpy(s2, s1);
    return s2;
}
 

void close_file(FILE* file)
{
    if (fclose(file) != 0)
    {
        printf("Can't close file");
        exit(EXIT_FAILURE);
    }
}


long int get_filesize(const char *filename)
{
    struct stat statbuf;

    if (stat(filename, &statbuf) == -1)
    {
        printf("failed to get size of %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return statbuf.st_size;
}


char* create_buffer(int size)
{
    char *buffer = (char *) calloc(size + 1, sizeof(char));
    if (buffer == NULL)
    {
        printf("no memory\n");
        free(buffer);
        exit(EXIT_FAILURE);
    }
    return buffer;
}


void print_text(char** text, int nlines)
{
    for (int i = 0; i < nlines; ++i) {
        printf("%s\n", text[i]);
    }
}


void free_text(char** text, int nlines)
{
    for (int i = 0; i < nlines; ++i) {
        free(text[i]);
        text[i] = nullptr;
    }
    free(text);
}
