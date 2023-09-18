#ifndef UTILITIES_H_
#define UTILITIES_H_

char * my_strdup(const char* s1);

void close_file(FILE* file);

long int get_filesize(const char *filename);

char* create_buffer(int size);

void print_text(char** text, int nlines);

void free_text(char** text, int nlines);

#endif