#include "main.h"

int main(void)
{
    char *command = NULL;
    char *cmd = NULL;
    char **av = NULL;
    print_string("($) ");
    command = get_command();
    av = split_string(command, " \n");
    cmd = serach_in_path(av[0]);
    printf("count1 = %s\n", cmd);
    /* return to original command if not found and also return if value /bin/ls */
    if (cmd == NULL)
        av[0] = command;
    else
        av[0] = cmd;
    execute(av);

    return (0);
}