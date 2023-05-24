#include "main.h"

/**
 * get_path - get paths
 * Return: directory of pathes
 */
char **get_path()
{
	char **av;
	char *envv = NULL;

	envv = _getenv("PATH");
	av = split_string(envv, ":");
	return (av);
}

/**
 * serach_in_path - search in path
 * @str: pointer to command
 * Return: path of command
 */
char *serach_in_path(char *str)
{
	char **av = NULL;
	char *str_return = NULL;
	int count = 0;
	struct stat st;

	av = get_path();
	while (av[count])
	{
		_strcat(av[count], "/");
		_strcat(av[count], str);
		if (stat(av[count], &st) == 0)
		{
			break;
		}
		count++;
	}
	/* return NULL if command not found */
	if (av[count] == NULL)
		return (NULL);
	str_return = _strdup(av[count]);
	free_2D(av);
	
	return (str_return);
}

/**
 * check_path - the status
 * @str: pointer to path
 *  Return: 1 found or 0 not found
 */
int check_path(char *str)
{
	struct stat st;

	if (stat(str, &st) == 0)
		return (1);

	return (0);
}

/**
 * print_env - print environment
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * _getenv - get environment
 * @name: pointer to string of variable
 * Return: value of variable
 */
char *_getenv(char *name)
{
	int i = 0, len = _strlen(name);
	char **env = environ;

	while (env[i] != NULL)
	{
		if ((_strncmp(env[i], name, len) == 0) && env[i][len] == '=')
			return (&env[i][len + 1]);
	i++;
	}
	return (NULL);
}
