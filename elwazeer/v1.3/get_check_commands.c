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
char *get_command()
{
    char *str = NULL;
    size_t size = 0;
    ssize_t check_read;

    check_read = getline(&str, &size, stdin);
    if (check_read == -1)
        return (NULL);

    return (str);
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

    av = split_string(str, " \n", &count);

    if (!(_strcmp("ls", av[0])) || !(_strcmp("/bin/ls", av[0])))
    {
        execute_ls(av);
    }

    else if (!(_strcmp("exit", av[0])))
    {
        free_2D(av);
        exit(EXIT_SUCCESS);
    }
}

/**
 * split-string - split strings
 * @str: pointer to string that will be splited
 * Return: array of sring content new split strings
 */

char **split_string(char *str, char *delim, int *len)
{
    int max_split = 1024;
    char **splits;
    char *split, *command;
    int count = 0;

    command = _strdup(str);

    splits = (char **)malloc(sizeof(char *) * max_split);
    if (splits == NULL)
        return (NULL);

    split = strtok(str, delim);
    while (split != NULL)
    {
        splits[count++] = _strdup(split);
        split = strtok(NULL, delim);
    }
    splits[count] = NULL;
    *len = count;
    free(command);
    return (splits);
}

/**
 * free_2D - free arr 2d
 * @arr: pointer to pointer
 * Return: void
 */
void free_2D(char **arr)
{
    int i = 0;

    for (i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

extern char **environ;
/**
 * _getenv - get environment
 * @str: pointer to string of variable
 * Return: value of variable
 */
char *_getenv(char *name)
{
    int i, len = _strlen(name);
    char **env = environ;

    while (env[i] != NULL)
    {
        if ((_strncmp(env[i], name, len) == 0) && env[i][len] == '=')
            return (&env[i][len + 1]);
        i++;
    }
    return (NULL);
}