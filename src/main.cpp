#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "print_triangle.h"
#include "utilities.h"


void read_file(const char *filename)
{
    long int filesize = get_filesize(filename);
    printf("%ld\n", filesize);

    char *buffer = create_buffer(filesize);

    FILE *file = fopen(filename, "r"); 
    fread(buffer, sizeof(char), filesize, file);
    close_file(file);

    buffer[filesize] = '\n';

    int nlines = 0;

    for (int i = 0; i <= filesize; i++) {
        if (buffer[i] == '\n') {
            nlines++;
            buffer[i] = '\0';
        }
    }

    char** text = (char **) calloc(nlines, sizeof(char *));
    if (text == NULL)
    {
        printf("no memory\n");
        free(buffer);
        free(text);
        exit(EXIT_FAILURE);
    }

    text[0] = buffer;
    for (int i = 1, j = 1; i < filesize && j < nlines; i++) {
        if (buffer[i] == '\0') {
            text[j++] = strdup(buffer + i + 1);
        }
    }

    free(buffer);

    print_text(text, nlines);

    free_text(text, nlines);
}


int main()
{
    char str[] = "C:\\Users\\eliza\\VSCodeProjects\\push-kin\\src\\file.txt";
    read_file(str);
    
    return 0;
}
