#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

extern char **environ;

char *_getenv(const char *name)
{
    char **env = environ;
    int len = 0;
    len = strlen(name);

    while (*env)
    {
        if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
            return ((*env) + len + 1);

        env++;
    }
    return ("(null)");
}

