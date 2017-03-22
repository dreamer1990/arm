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

    int val = 0; 
    while(1)
    {
        ioctl(fd, 1, val);
        sleep(1);
        ioctl(fd, 0, val);
        sleep(1);
        val ++;
        if(val == 4)
            val = 0;
    }

    close(fd);
    return 0;
}
