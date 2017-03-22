#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>



int main(void)
{

    //创建一个目录
    if (mkdir("test1", 0644) < 0)
        perror("mkdir");

    //删除一个目录 该目录一定为空
    if (rmdir("test_A") < 0)
        perror("rmdir");

    return 0;
}

