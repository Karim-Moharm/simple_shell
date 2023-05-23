#include <stdio.h>

int search_for_char(char *cmd, char ch)
{
    while (*cmd)
    {
        if (*cmd == ch)
            return (1);
        cmd++;
    }
        return (0);
}

int main(void)
{
    char str[] = "searching for / in string";
    char str2[] = "searching for * in string";
    int ret = search_for_char(str, '/');
    int ret2 = search_for_char(str2, '/');

    printf("%d\n", ret);
    printf("%d\n", ret2);
}