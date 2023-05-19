#include "shell.h"
#include <stdlib.h>

void free_2D(char **arr)
{
    int i = 0;

    for (i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
