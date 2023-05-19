#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"


char *_getline(void)
{
    char *lineRead = NULL;
    size_t lineSize = 0;

    if (isatty(STDERR_FILENO)) /* check if the file referes to terminal or not (interactive mode)*/
    {
        _puts("$ ");
    }

    if (getline(&lineRead, &lineSize, stdin) == -1)
    {
        free(lineRead);
        exit(EXIT_SUCCESS);
    }

    return (lineRead);
}


void print_env()
{
    char **env = environ;

    while (*env)
    {
        _puts(*env++);
        _puts("\n");
    }
}