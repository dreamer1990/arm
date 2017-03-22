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
    int fd = 0;

    //打开一个文件 读写的方式
    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    printf("fd = %d\n", fd);


    write(fd, "A", 1);
    printf("offset: %ld\n", lseek(fd, 0, SEEK_CUR));

    //偏移到1M的地方  产生空洞文件
    lseek(fd, 1024 * 1024, SEEK_CUR);

    printf("offset: %ld\n", lseek(fd, 0, SEEK_CUR));
    write(fd, "hello world", 11);

    printf("offset: %ld\n", lseek(fd, 0, SEEK_CUR));

    //关闭文件
    close(fd);
    return  0;
err0:
    return -1;
}
