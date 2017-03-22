#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file(test)\n", argv[0]);
        return -1;
    }

    int fd;
    int ret;
    fd = open(argv[1], O_RDWR); //--> test_open (test.ko)
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    printf("fd : %d\n", fd);

    ret = write(fd, "hello", 5);//文件偏移量往后走;
    printf("ret : %d\n", ret);

    lseek(fd, 0, SEEK_SET);

    char buf[100] = {};
    ret = read(fd, buf, 100);
    printf("ret: %d buf: %s\n", ret, buf);

    close(fd);                  //--> test_close(test.ko)
    return 0;
}
