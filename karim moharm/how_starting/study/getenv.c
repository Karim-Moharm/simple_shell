#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char *env_var1;

    env_var1 = getenv("USER");

    char *env_var2 = getenv("SHELL");
    char *env_var3 = getenv("UNDEFINED");
    char *env_var4 = getenv("TERM");
    /* return null when it cant find the file specified in its argument */
    if (env_var1 == NULL)
    {
        perror("file cant found\n");
        return (1);
    }

    printf("USER is %s\n\n", env_var1);
    printf("SHELL is%s\n\n", env_var2);
    printf("UNDEFINED is%s\n\n", env_var3);
    printf("TERMINAL is%s\n\n", env_var4);
}
