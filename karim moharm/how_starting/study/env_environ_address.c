#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[], char *env[])
{
    printf("address of environ is %p\n", environ);
    printf("address of env is %p\n", env);

    if (env == environ)
        printf("both having the same address\n");
    else
        printf("Not having same address\n");

    return 0;

}
