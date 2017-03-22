#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/fb.h>

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

    int i, j;
    unsigned int col = 0xff00;

    struct fb_var_screeninfo var;
    ioctl(fd, FBIOGET_VSCREENINFO, &var);
    struct fb_fix_screeninfo fix;
    ioctl(fd, FBIOGET_FSCREENINFO, &fix);

    while(1)
    {
        for(i = 0; i < var.yres; i++)
        {
            for(j = 0; j < var.xres; j++)
            {
                if(var.bits_per_pixel == 32)
                    write(fd, &col, 4);
                else
                    return -1;
            }
        }

        col <<= 8;
        if(col == 0xff000000)
            col = 0xff;
        lseek(fd, 0, SEEK_SET);
    }


    close(fd);
    return 0;
}
