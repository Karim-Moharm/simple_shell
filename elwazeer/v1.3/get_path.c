#include "main.h"

/**
 * @get_path - get paths
 * @str: pointer to string
 * Return: directory of pathes
 */
char **get_path()
{
    char **av;
    char *envv;

    envv = (char *)malloc(sizeof(char) * MAX_SIZE);
    if (envv == NULL)
        return (NULL);
    envv = _getenv("PATH");
    av = split_string(envv, ":");

    return (av);
}

/**
 * serach_in_path - search in path
 * @str: pointer to command
 * Return: path of command
 */
char *serach_in_path(char *str)
{
    char **av;
    char *str_return;
    int count = 0;
    struct stat st;

    av = get_path();
    while (av[count])
    {
        strcat(av[count], "/");
        strcat(av[count], str);
        if (stat(av[count], &st) == 0)
        {
            break;
        }
        count++;
    }
    str_return = _strdup(av[count]);
    free_2D(av);
    return (str_return);
}

/**
 * print_env - print environment
 * Return: void
 */
void print_env(void)
{
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}