#include <stdio.h>
#include <stdlib.h>

/**
 *  modify an existing environment variable
 */

int main(void)
{
    char *my_var = "PATH";
    char *my_value = "/usr/local/bin:/usr/bin:/bin";
    printf("PATH-before setenv\n%s\n\n", getenv(my_var));

    setenv(my_var, my_value, 1);

    printf("PATH-after setenv\n%s\n\n", getenv(my_var));

    char *new_value = "/usr/local/bin:/usr/bin:/bin:/opt/local/bin";
    setenv(my_var, new_value, 1);

    printf("PATH-after setenv\n%s\n\n", getenv(my_var));
    
    unsetenv(my_var);
    printf("after unset became: \n%s\n", getenv(my_var));

    return 0;
}
