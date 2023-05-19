#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _puts(char *str);
int print_string(char *str);

char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);

char *get_command(char *line);
void check_command(char *str);

void execute_ls();

#endif
