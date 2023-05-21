#include "shell.h"

extern char **environ;

/**
 * _getenv - get the environment variables
 * @name: name of varible
 * Return: all varibles of that environment  and null if failed
*/

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