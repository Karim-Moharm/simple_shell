#include "main.h"
#include <unistd.h>

/**
 * execute_ls - execute command ls
 * Return: void
 */
void execute_ls()
{
    char *argv[] = {"/bin/ls", NULL};
    if (execve(argv[0], argv, NULL) == -1)
        print_string("Error:");
}