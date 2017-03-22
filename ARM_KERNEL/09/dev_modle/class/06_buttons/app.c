#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char ** argv, char **env)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file\n", argv[0]);
        return -1;
    }
    
    int fd;
    fd = open(argv[1], O_RDWR);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    char buf[4] = {};
    while(1)
    {
        read(fd, buf, 4); 
        printf("%c %c %c %c\n", buf[0], buf[1], buf[2], buf[3]);
    }

    close(fd);
    return 0;
}
