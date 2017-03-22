#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/input.h>

int main(int argc, char ** argv, char **env)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file\n", argv[0]);
        return -1;
    }
    
    int fd;
    fd = open(argv[1], O_RDONLY);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    char buf[20];
    while(1)
    {
        read(fd, buf, 20);
        printf("key0: %s\n", buf);
    }

    close(fd);
    return 0;
}
