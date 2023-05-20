#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"


/* int main(void)
{
    char *path = _getenv("PATH");
    char *token = NULL;
    
    token = strtok(path, ":");
    while(token)
    {
        _puts(token);
        _puts("\n");
        token = strtok(NULL, ":");
    }

    return 0;
}
 */

/**
 * search_for_char - unsed to search for / in command entered by user
 * @cmd: the command entered by user
 * @ch: char to search for
 * 
 * return: 1 if the char was found, 0 if not found
*/
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