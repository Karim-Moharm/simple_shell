#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../simple_shell/shell.h"


extern char **environ;

char *_getenv(const char *name)
{
    char **env = environ;
    int len = 0;
    len = strlen(name);
    char *temp = NULL;

    while (*env)
    {
        if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
            return ((*env) + len + 1);

        env++;
    }
    return ("(null)");
}

int main(void)
{
    char *path = _getenv("PATH");
    int len = strlen(path);
    char *token = NULL;
    
    token = strtok(path, ":");
    while(token)
    {
        _puts(token);
        _puts("\n");
        token = strtok(NULL, ":");
    }

    return 0;
}

