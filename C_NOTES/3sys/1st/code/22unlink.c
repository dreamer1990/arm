#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>



int main(void)
{
    //删除一个现存的目录项
    if (unlink("a") < 0)
        perror("unlink");

    
    //删除一个文件或者目录
    if (remove("./test") < 0)
        perror("remove");

    if (rename("test1", "test_A") < 0)
        perror("rename");


    return 0;
}

