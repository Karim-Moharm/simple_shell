#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

    /* str_cpy = (char *)malloc(sizeof(char) * size); */
    /* if (str_cpy == NULL)
        return (NULL); */

    check_read = getline(&str_cpy, &size, stdin);
    if (check_read == -1)
    {
        free(str_cpy);
        exit(EXIT_FAILURE);
    }
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
    char **av;
    int count;

    av = split_string(str, &count);

    if (!(_strcmp("ls", av[0])) || !(_strcmp("/bin/ls", av[0])))
    {
        execute_ls(av);
    }

    else if (!(_strcmp("exit", av[0])))
    {
        free_2D(av);
        
        _exit(EXIT_SUCCESS);
=
        exit(EXIT_SUCCESS);

    }
}

/**
 * split-string - split strings
 * @str: pointer to string that will be splited
 * Return: array of sring content new split strings
 */

char **split_string(char *str, int *len)
{
    int max_split = 1024;
    char **splits;
    char *split, *command;
    int count = 0;

    command = strdup(str);

    splits = (char **)malloc(sizeof(char *) * max_split);
    if (splits == NULL)
        return (NULL);

    split = strtok(str, " \n");
    while (split != NULL)
    {
        splits[count++] = strdup(split);
        split = strtok(NULL, " \n");
    }
    splits[count] = NULL;
    *len = count;
    free(command);
    return (splits);
}

void free_2D(char **arr)
{
    int i = 0;

    for (i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}