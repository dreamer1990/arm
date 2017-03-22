#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "ioctl-dev.h"

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

/*
    ioctl();
    write();
    lseek();
    mmap();
*/
    int i, j;
    unsigned int col = 0xff00;
    while(1)
    {
        for(i = 0; i < 480; i++)
        {
            for(j = 0; j < 800; j++)
            {
                write(fd, &col, 4);
            }
        }

        col <<= 8;
        if(col == 0xff000000)
            col = 0xff;
    }


    close(fd);
    return 0;
}
