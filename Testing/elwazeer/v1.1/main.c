#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point
 * Return: 0 when success
 */
int main(void)
{
	char command[500];
	while (1)
	{
		print_string("($) ");
		get_command(command);
		check_command(command);
	}
	return (0);
}
