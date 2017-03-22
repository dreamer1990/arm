#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 1024

//off_t long int
off_t lseek(int fd, off_t offset, int whence);

/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
//#define SEEK_SET	0	/* Seek from beginning of file.  */
//#define SEEK_CUR	1	/* Seek from current position.  */
//#define SEEK_END	2	/* Seek from end of file.  */


int main(void)
{
    int fd = 0;
    int ret = 0;
    char buf[SIZE];

    long int offset = -1;

    //读写的方式打开文件
    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        //errorno
        perror("open"); 
        goto err0;
    }

    //文件打开的时候  没有以追加的方式打开   offset默认是0
    offset = lseek(fd, 0, SEEK_CUR);
    printf("offset: %ld\n", offset);

    lseek(fd, 10, SEEK_SET);
    write(fd, "hello", 5);

    offset = lseek(fd, 0, SEEK_CUR);
    printf("offset: %ld\n", offset);


    //关闭文件
    close(fd);

    return 0;
err0:
    return -1;
}
