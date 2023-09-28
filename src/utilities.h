#ifndef UTILITIES_H_
#define UTILITIES_H_

struct Text
{
    char **data;
    int nlines;
};


char * my_strdup(const char* s1);

void close_file(FILE* file);

int get_filesize(const char *filename);

char* create_buffer(int size);

void print_text(Text * text);

void free_text(Text * text);

Text read_file(const char *filename);


#endif