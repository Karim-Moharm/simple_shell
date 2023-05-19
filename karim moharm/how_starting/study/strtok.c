#include <stdio.h>
#include <string.h>

char *split_str(char *str);

int main(void)
{
  /*  char *strtok(char *str, const char *delim); */
/*
    char str[] = "welcom to wsl ubuntu-version";
    char *delim = " ";
    char *token = NULL;

    token = strtok(str, delim);

    while (token)
    {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }
*/

    char s[] = "this is string --   --- $$$$$, ## -##";
    char *str_ret;

    str_ret = split_str(s);
    return 0;
}

char *split_str(char *str)
{
    char *token;
    const char *delim = " ";

    token = strtok(str, delim);

    while(token)
    {
        puts(token);
        token = strtok(NULL, delim);
    }
    return (token);


}
