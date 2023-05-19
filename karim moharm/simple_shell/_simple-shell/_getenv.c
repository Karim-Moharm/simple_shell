#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

/* int main(void)
{
    char *ret = _getenv("PATH");
    char *ret2 = _getenv("USER");
    char *ret3 = _getenv("NOT_FOUND");
    char *ret4 = _getenv("SHELL");
    char *ret5 = _getenv("NONNNN");
    char *ret6 = _getenv("HOME");

    printf("%s\n\n", ret);
    printf("%s\n\n", ret2);
    printf("%s\n\n", ret3);
    printf("%s\n\n", ret4);
    printf("%s\n\n", ret5);
    printf("%s\n\n", ret6);
    return 0;
}
 */