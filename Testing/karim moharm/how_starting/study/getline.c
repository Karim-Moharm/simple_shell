/* #include "shell.h" */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* getline(char **lineptr, size_t *n, FILE *stream)
     */

    char *buffer = NULL;
    size_t n = 0;

    buffer = malloc(sizeof(char) * n);
    printf("$ "); 
    getline(&buffer, &n, stdin);

    printf("%s", buffer);
    free(buffer);
    
     
    return 0;
}
