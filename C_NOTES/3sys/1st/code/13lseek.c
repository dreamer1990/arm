#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int ret = 0;

    //标准输入不可以seek
    ret = lseek(STDIN_FILENO, 10, SEEK_CUR);
    if (ret < 0)
    {
        perror("lseek"); 
        goto err0;
    }
    else
    {
        printf("lseek ok....\n"); 
    }

    return 0;
err0:
    return -1;
}




