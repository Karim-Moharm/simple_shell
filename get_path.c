#include "main.h"

/**
 * get_path - get paths
 * Return: directory of pathes
 */
char **get_path()
{
	char **av;
	char *envv;

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
	char **av;
	char *assist = NULL;
	int count = 0;
	struct stat st;

	av = get_path();
	while (av[count])
	{
		assist = full_path(av[count], str);
		if (stat(assist, &st) == 0)
		{
			free_2D(av);
			return (assist);
		}
		count++;
		free(assist);
	}
	/* return NULL if command not found */
	free_2D(av);
	return (NULL);
}

/**
 * full_path - return full path to check
 * @dir: pointer to path
 * @cmd: pointer to command
 * Return: full path meaning concatenate path with cmd to check
 */
char *full_path(char *dir, char *cmd)
{
	char *str_return = NULL;
	int len, i, len_2;

	len_2 = _strlen(dir) + 1;
	len = _strlen(dir) + _strlen(cmd) + 2;

	str_return = (char *)malloc(sizeof(char) * len);
	if (str_return == NULL)
		return (NULL);

	for (i = 0; *(dir + i) != '\0'; i++)
		*(str_return + i) = *(dir + i);

	*(str_return + i) = '/';

	for (i = 0; *(cmd + i) != '\0'; i++)
		*(str_return +  len_2 + i) = *(cmd + i);
	*(str_return + len_2 + i) = '\0';

	return (str_return);
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
