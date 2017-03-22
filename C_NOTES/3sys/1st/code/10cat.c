#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 4096


//标准的文件描述符
///usr/include/unistd.h
/* Standard file descriptors.  */
//#define	STDIN_FILENO	0	/* Standard input.  */      标准输入
//#define	STDOUT_FILENO	1	/* Standard output.  */     标准输出
//#define	STDERR_FILENO	2	/* Standard error output.  */   标准错误输出


int main(int argc, char **argv)
{
    int ret = 0;
    int fd = 0;
    char buf[SIZE];

    //标准输入 标准输出 标准错误输出都是系统已经默认打开的文件描述符
    
    printf("argc = %d\n", argc);

    //后面没有跟任何文件的时候
    if (argc == 1)
    {
        while(1)
        {
            //从标准输入读取数据
            ret = read(STDIN_FILENO, buf, SIZE); 
            if (strncmp(buf, "exit", 4) == 0)    
                //退出循环
                break;

            //将数据写入到标准输出
            write(STDOUT_FILENO, buf, ret);
        }
    }
    else if (3 == argc)
    {
        if (strncmp(argv[1], ">>", 2) == 0)
        {
            //以追加的方式打开文件
            fd = open(argv[2], O_WRONLY | O_APPEND | O_CREAT, 0644);
            if (fd < 0)
            {
                perror("open"); 
                goto err0;
            }
        }
        else if (strncmp(argv[1], ">", 1) == 0)
        {
            fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); 
            if (fd < 0)
            {
                perror("open"); 
                goto err0;
            }
        }
        else
        {
            printf("usage: ./a.out >> file or ./a.out >> file or ./a.out\n"); 
        }

        while(1)
        {
            //从标准输入读取数据
            ret = read(STDIN_FILENO, buf, SIZE); 
            if (strncmp(buf, "exit", 4) == 0)
                break;
            if (ret <= 0)
                break;
            write(fd, buf, ret);
        }
    }

    //关闭文件
    if (fd > 0)
        close(fd);

    return 0;
err0:
    return -1;
}


