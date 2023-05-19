#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *user = getenv("USER");
    printf("USER=%s\n", user);
    int ret = setenv("USER", "iamKarimMoharm", 1);
    
    if (ret < 0)
    {
        perror("error in setenv");
        return 1;
    }
    const char *newuser = getenv("USER");
    printf("USER=%s\n", newuser);

    unsetenv("USER");
    const char *user2 = getenv("USER");
    printf("USER=%s\n", user2);

    return 0;
}
