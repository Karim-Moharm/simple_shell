#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
    
    while (*environ)
    {
        printf("%s\n", *environ);
        environ++;
    }

    return 0;
}



