#include <unistd.h>
#include <stdio.h>
#include "shell.h"
#include <string.h>

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



/* int main(void)
{ */
    /* puts("hello $$%$$%b \n \t");
    _puts("hello $$%$$%b \n \t");
    _puts("4444");
    _puts("\n"); */

/*     char s1[] = "HElloddddddddddddd"; 
    char s2[] = "Hellofffflfkkk"; 

    int cmp = _strcmp(s1, s2);
    int cmp2 = _strcmp(s1, s2);
    printf("%d\n", cmp);
    printf("%d\n", cmp2); 

}  */