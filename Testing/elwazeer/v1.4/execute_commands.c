#include "main.h"

/**
 * execute_ls - execute command ls
 * Return: void
 */

void execute_ls(char **av)
{
    av[0] = "/bin/ls";
    if (execve(av[0], av, NULL) == -1)
        perror(av[0]);
}

void execute(char **av)
{
    if (execve(av[0], av, NULL) == -1)
    {
        perror(av[0]);
    }
}