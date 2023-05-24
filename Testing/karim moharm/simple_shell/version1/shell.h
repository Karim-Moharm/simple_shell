#ifndef _SHELL_H
#define _SHELL_H

int _putchar (char c);
int _puts(char *str);
void free_2D(char **arr);
char *_getline(void);
void print_env();
char **tokenize(char *lineptr);

#endif
