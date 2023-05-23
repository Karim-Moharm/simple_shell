#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **tokenize(char *lineptr)
{
	char **command = NULL;
	char *token, *delim = " \n\t";
	int tok_counter = 0;

	command = (char **)malloc(sizeof(char *) * 1024); 

	if (command == NULL)
	{
		free(command);
		exit(EXIT_FAILURE);
	}

	token = strtok(lineptr, delim);
    if (token == NULL)
    {
        free(command);
		exit(EXIT_FAILURE);
    }

	while (token)
	{
		command[tok_counter] = strdup(token);
		token = strtok(NULL, delim);
		tok_counter++;
	}
	command[tok_counter] = NULL;
	return (command);
}


int main(void)
{
    char name[] = "karimmoharm\n \tsaieeddd";
    
    tokenize(name);
    printf("%s\n", name);
 
    


}