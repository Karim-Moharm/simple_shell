#include <stdio.h>
#include "shell.h"
#include <sys/stat.h>

int main(void)
{
    /* int stat(const char *pathname, struct stat *statbuf) */
    
    struct stat sfile;
    char *pathname = "stat.c";

    /* stat return 0 in success and -1 in error */

    if ((stat(pathname, &sfile)) == -1)
    {
        perror("stat failed\n");
        exit(100);
    }

    /* print some information of the file from stat struct 
     * stat struct are defined in man 2 stat */
    
    printf("stat size os %ld\n", sfile.st_size);
    printf("modification time of the file %ld\n", sfile.st_mtime);
    printf("last time at which the file was accessed %ld\n", sfile.st_atime);
    printf("Owner ID: %d\n", sfile.st_uid);
    printf("Permissions: %o\n", sfile.st_mode); 
    return 0;

}
