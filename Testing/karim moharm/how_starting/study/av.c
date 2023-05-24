#include <stdio.h>
int main(__attribute__((unused))int ac, char **av)
{
    int i = 1;

    for (i; av[i] != NULL; i++)
        printf("%s ", av[i]);
    printf("\n");
    

    return 0;
}
