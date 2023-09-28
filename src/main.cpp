#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "cmp_funcs.h"
#include "utilities.h"


int main()
{
    char str[] = "C:\\Users\\eliza\\VSCodeProjects\\push-kin\\src\\file.txt";
    Text text = read_file(str);

    printf("aaa %d\n", find_min(text.data, text.nlines, sizeof(char *), compare_strs));

    selection_sort(text.data, text.nlines, sizeof(char *), compare_strs);

    print_text(&text);

    free_text(&text);
    return 0;
}
