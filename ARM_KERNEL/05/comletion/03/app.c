#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void func(int sig)
{
    printf("sig: %d\n", sig);
}

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file(test)\n", argv[0]);
        return -1;
    }

    signal(SIGINT, func);

    int fd;
    fd = open(argv[1], O_RDWR);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    read(fd, 0, 0);

    close(fd);
    return 0;
}
