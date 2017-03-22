#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/fb.h>

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

    struct fb_fix_screeninfo fix;
    ioctl(fd, FBIOGET_FSCREENINFO, &fix);
    struct fb_var_screeninfo var;
    ioctl(fd, FBIOGET_VSCREENINFO, &var);

    printf("smem_start: %lx smem_len: %u line_length: %u\n", fix.smem_start, fix.smem_len, fix.line_length);
    printf("xres: %u yres: %u bits_per_pixel: %u\n", var.xres, var.yres, var.bits_per_pixel);

    int i, j;
    unsigned int col = 0xff;
    for(i = 0; i < var.yres; i++)
    {
        for(j = 0; j < var.xres; j++)
        {
            write(fd, &col, 4);
        }
    }

    close(fd);
    return 0;
}
