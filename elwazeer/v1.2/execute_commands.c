#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * execute_ls - execute command ls
 * Return: void
 */

void execute_ls(char **av)
{
    av[0] = "/bin/ls";
    if (execve(av[0], av, NULL) == -1)
        print_string("Error:");
}