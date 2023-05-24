#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: 1 if s1 > s2, 0 if s1 = s2 and -1 if s1 < s2
 */
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

/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */

int _strlen(const char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}

/**
 * _strdup - duplicate the string to new mem location
 * @str: string to be duplicated
 * Return: the new string
*/
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

/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */

char *_strcat(char *dest, const char *src)
{
    int len = 0;
    int i = 0;

    len = _strlen(dest);
    
    while (src[i] != '\0')
    {
        dest[len++] = src[i++];
    }
    dest[len] = '\0';

    return (dest);
}





int main(void)
{ 
    
    /* char s1[] = "HElloddddddddddddd"; 
    char s2[] = "Hellofffflfkkk"; 

    int cmp = _strcmp(s1, s2);
    int cmp2 = strcmp(s1, s2);
    printf("%d\n", cmp);
    printf("%d\n", cmp2); 

    char *new1 = NULL;
    char *new2 = NULL;
    char str[] = "karim m";

    new1 = strdup(str);
    new2 = _strdup(str);

    printf("%s\n", new1);
    printf("%s\n", new2); */

    char dest[] = "hello";
    char src[] = "world";
    
    printf("%s\n", _strcat(dest, src));
    /* printf("%s\n",  strcat(dest, src)); */


} 