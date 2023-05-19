#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * execute_ls - execute command ls
 * Return: void
 */

void execute_ls(char *str)
{
    int count;
    char **argv = split_string(str, &count);
    printf("%d\n", count);
    /*  printf("3\n");
     argv[0] = "/bin/ls";
     for (i = 0; i <= count; i++)
     {
         printf("4\n");
         printf("%s\n", argv[i]);
     } */

    printf("5\n");
    if (execve("/bin/ls", argv, NULL) == -1)
        print_string("Error:");
}