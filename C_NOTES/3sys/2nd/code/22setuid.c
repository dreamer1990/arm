#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    if (setuid(500) < 0)
        perror("setuid");
    
    printf("uid: %u\n", getuid());

    //没有权限
    if (setgid(500) < 0)
        perror("setgid");

    printf("gid: %d\n", getgid());



    return 0;
}


