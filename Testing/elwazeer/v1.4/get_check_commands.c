#include "main.h"

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

    av = split_string(str, " \n");

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

char **split_string(char *str, char *delim)
{
    char **splits;
    char *split, *command;
    int count = 0;

    command = _strdup(str);

    splits = (char **)malloc(sizeof(char *) * MAX_SIZE);
    if (splits == NULL)
        return (NULL);

    split = strtok(str, delim);
    while (split != NULL)
    {
        splits[count++] = _strdup(split);
        split = strtok(NULL, delim);
    }
    splits[count] = NULL;
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
