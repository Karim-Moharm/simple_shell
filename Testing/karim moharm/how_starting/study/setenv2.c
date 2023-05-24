#include <stdio.h>
#include <stdlib.h>

/**
 * add an environmetn variable called my_var and set it to hello, world
 */

int main(void)
{
    char *my_var = "MY_VAR";
    char *my_value = "Hello, world";

    printf("the value of %s is %s\n", my_var, getenv(my_var));
    
    setenv(my_var, my_value, 1);

    printf("the value of %s is %s\n", my_var, getenv(my_var));

    unsetenv(my_var);

    printf("the value of %s is %s\n", my_var, getenv(my_var));
    return 0;
}
