#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/watchdog.h>

int main(int argc, char ** argv, char **env)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file.\n", argv[0]);
        return -1;
    }

    int fd;
    fd = open(argv[1], O_RDWR);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    int i, j;
    unsigned int col = 0xff;
    for(i = 0; i < 1024; i++)
    {
        for(j = 0; j < 768; j++)
        {
            write(fd, &col, 4);
        }
    }

    close(fd);
    return 0;
}
