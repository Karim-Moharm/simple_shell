#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"

/**
 * _getline - get the command from user 
 * 
 * Description: first check if the file referes to terminal or not (interactive mode)
 * using isatty function then prints $ and take the command from the user
 * 
 * Return: the entered command
*/
char *_getline(void)
{
    char *lineRead = NULL;
    size_t lineSize = 0;

    if (isatty(STDERR_FILENO)) /* */
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

/**
 * print_env - function that print the environment var
 * Return: nothing
*/
void print_env()
{
    char **env = environ;

    while (*env)
    {
        _puts(*env++);
        _puts("\n");
    }
}