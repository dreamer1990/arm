#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    
    int ret = 0;

    //access 进行一些存取权限测试
    if (0 == access("txt", R_OK))
        printf("Read ok....\n");

    if (0 == access("txt", W_OK))
        printf("Write ok...\n");

    if (0 == access("txt", X_OK))
        printf("execute ok...\n");

    if (0 == access("txt", F_OK))
        printf("File exist....\n");

    
    //更改掩码
    umask(0444);


    return 0;
}
