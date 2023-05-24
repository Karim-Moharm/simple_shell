#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * get_command - create new command
 * @line: pointer to store new command
 * Return: command
 */
char *get_command(char *line)
{
    char *str_cpy = NULL;
    size_t size = 0;
    ssize_t check_read;

    str_cpy = (char *)malloc(sizeof(char) * size);
    if (str_cpy == NULL)
        return (NULL);

    check_read = getline(&str_cpy, &size, stdin);
    if (check_read == -1)
        return (NULL);

    _strcpy(line, str_cpy);

    free(str_cpy);
    return (line);
}

/**
 * check_command - check command
 * @str: pointer to command to check
 * Return: void
 */
void check_command(char *str)
{
    if (!(_strcmp("ls\n", str)) || !(_strcmp("/bin/ls\n", str)))
    {
        execute_ls();
    }

    else if (!(_strcmp(str, "exit\n")))
        exit(0);
}
