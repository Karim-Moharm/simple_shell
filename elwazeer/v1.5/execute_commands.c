#include "main.h"

/**
 * execute - execute command
 * @av: pointer to av
 * Return: void
 */

void execute(char **av)
{
    if (execve(av[0], av, NULL) == -1)
    {
        perror(av[0]);
        exit(EXIT_FAILURE);
    }
}