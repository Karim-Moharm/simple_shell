#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;

	line = (char *)malloc(sizeof(char) * n);

	nread = getline(&line, &n, stdin);
	printf("n= %ld\n %s\n", n, line);

	free(line);
	return (0);
}
