#include <stdio.h>

/**
 * main - Entry Point
 * Return: Always 0
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		printf("%s\n", argv[i]);
	return (0);
}
