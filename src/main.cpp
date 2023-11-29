#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "cmp_funcs.h"
#include "pushkin.h"


int main()
{
    char str[] = ".\\src\\file.txt";
    Text text = read_file(str);

    // printf("aaa %d\n", find_min_index(text.data, text.nlines, sizeof(char *), str_cmp));

    selection_sort(text.data, text.nlines, sizeof(char *), reverse_str_cmp_letters); // reverse_str_cmp     reverse_str_cmp_letters     str_cmp     str_cmp_letters

    print_text(&text);

    free_text(&text);
    return 0;
}
