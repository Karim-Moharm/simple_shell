#include "shell.h"
#include <stdlib.h>

/**
 * free_2D - deallocate an array of pointer to string
 * @arr: pointer to pointer string
 * Return: Nothing  
*/
void free_2D(char **arr)
{
    int i = 0;

    for (i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
