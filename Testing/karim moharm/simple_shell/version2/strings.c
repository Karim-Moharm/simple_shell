#include <unistd.h>
#include <stdio.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>

int _putchar(char c)
{
    return (write(STDOUT_FILENO, &c, 1));
}

int _puts(char *str)
{
    int i = 0;
    int count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
        count++;
    }
    return (count);
}

int _strcmp(const char *str1, const char *str2)
{
    while (*str1 == *str2 && *str1 && *str2)
    { 
        str1++;
        str2++;
    }
    if (*str1 > *str2)
        return (1);
    else if (*str1 < *str2)
        return (-1);
    
    return (0);
    
}

int _strlen(const char *s)
{
    int len = 0;

    while (s[len++])
        ;;
    return (len);
}

char* _strdup(const char* str)
{
    char *new_str = NULL;
    char *ret_new;

    if (str == NULL)
        return (NULL);

    new_str = malloc(sizeof(char) * _strlen(str));
    ret_new = new_str;
    
    if (new_str == NULL)
        return (NULL);
    
    while (*str)
        *new_str++ = *str++;
    *new_str = '\0';

    return (ret_new);

}

/* int main(void)
{ */
    
    /* char s1[] = "HElloddddddddddddd"; 
    char s2[] = "Hellofffflfkkk"; 

    int cmp = _strcmp(s1, s2);
    int cmp2 = strcmp(s1, s2);
    printf("%d\n", cmp);
    printf("%d\n", cmp2);  */

/*     char *new1 = NULL;
    char *new2 = NULL;
    char str[] = "karim m";

    new1 = strdup(str);
    new2 = _strdup(str);

    printf("%s\n", new1);
    printf("%s\n", new2);

} */ 

