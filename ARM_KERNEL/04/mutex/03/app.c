#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

void func(int signum)
{
    printf("signum: %d\n", signum);
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

    close(fd);
    return 0;
}
