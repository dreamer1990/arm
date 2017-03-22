#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 128

int main(void)
{
    int ret = 0;
    int fd = 0;
    char buf[SIZE];

    //打开文件
    fd = open("txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }
    printf("fd = %d\n", fd);

    while(1)
    {
        //从标准输入获取一个字符串
        fgets(buf, SIZE, stdin); 

        if (strncmp(buf, "exit", 4) == 0)
            break;
        //向文件中写数据
        ret = write(fd, buf,  strlen(buf));
        printf("ret = %d\n", ret); 
    }

    //关闭文件
    close(fd);

    return 0;
err0:
    return -1;
}
