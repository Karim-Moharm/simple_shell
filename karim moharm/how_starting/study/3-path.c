#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char *path = getenv("PATH");
    int len = strlen(path);
    printf("len = %d\n", len);

    while (i < len)
    {
        if (path[i] == ':')
        {
            path[i] = '\n';
        }
        printf("%c", path[i]);
        i++;
    }
    printf("\n");
    return 0;
}
