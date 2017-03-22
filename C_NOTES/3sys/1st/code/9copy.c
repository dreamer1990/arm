#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


//usage: ./a.out src_file dest_file

int main(int argc, char **argv)
{
    if (3 != argc)
    {
        printf("usage: ./a.out file1 file2\n"); 
        goto err0;
    }

    char buf[128];
    int fd_in, fd_out;
    int ret = 0;

    //打开第一个文件
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in < 0)
    {
        perror("file1 open"); 
        goto err0;
    }

    //以只写的方式打开第二个文件
    fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out < 0)
    {
        perror("file2 open"); 
        goto err0;
    }

    while(1)
    {
        //从文件中读取数据
        ret = read(fd_in, buf, 128); 
        //文件读取完毕
        if (ret <= 0)
            break;
        //写数据到文件中    
        write(fd_out, buf, ret);
    }


    //关闭文件
    close(fd_in);
    close(fd_out);
    return 0;
err0:
    if (fd_in > 0)
        close(fd_in);
    return -1;
}







