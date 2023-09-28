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


int get_filesize(const char *filename)
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


void print_text(Text * text)
{
    for (int i = 0; i < text->nlines; i++) {
        printf("%s\n", text->data[i]);
    }
}


void free_text(Text * text)
{
    for (int i = 0; i < text->nlines; i++) {
        free(text->data[i]);
        text->data[i] = nullptr;
    }
    free(text->data);
}


Text read_file(const char *filename)
{
    int filesize = get_filesize(filename);
    printf("%d\n", filesize);

    char *buffer = create_buffer(filesize);

    FILE *file = fopen(filename, "r"); 
    fread(buffer, sizeof(char), filesize, file);
    close_file(file);

    buffer[filesize] = '\n'; 

    int nlines = 0;

    for (int i = 0; i <= filesize; i++)
    {
        if (buffer[i] == '\n')
        {
            nlines++;
            buffer[i] = '\0';
        }
    }

    char** data = (char **) calloc(nlines, sizeof(char *));
    if (data == NULL)
    {
        printf("no memory\n");
        free(buffer);
        free(data);
        exit(EXIT_FAILURE);
    }

    data[0] = buffer;
    for (int i = 1, j = 1; i < filesize && j < nlines; i++) 
    {
        if (buffer[i] == '\0') 
        {
            data[j] = strdup(buffer + i + 1);
            j++;
        }
    }
    
    Text text = {
        data,
        nlines
    };

    return text;
}
