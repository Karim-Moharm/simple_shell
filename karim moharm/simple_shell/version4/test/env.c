#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../shell.h"

extern char **environ;

void print_env()
{
    char **env = environ;

    while (*env)
    {
        _puts(*env++);
        _puts("\n");
    }
}

int main()
{
    print_env();

}