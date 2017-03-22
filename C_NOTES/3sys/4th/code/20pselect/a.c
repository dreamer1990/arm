#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

#define SIZE 128


int main(void)
{
    int fdr = -1;
    int fdw = -1;
    int fdmax = -1;
    int ret = 0;
    char buf[SIZE];
    //读的集合
    fd_set  readfds;
    struct timespec tmo = {
        .tv_sec = 3,    //秒
        .tv_nsec = 0, //纳秒
    };

    //以只读的方式打开管道1
    fdr = open("fifo1", O_RDONLY);
    if (fdr < 0)
    {
        perror("open"); 
        goto err0;
    }
    printf("open fifo1 for read succesfully...\n");

    //以只写的方式打开管道2
    fdw = open("fifo2", O_WRONLY);
    if (fdw < 0)
    {
        perror("open"); 
        goto err0;
    }
    printf("open fifo2 for write succesfully...\n");

    fdmax = fdr + 1;
    
    while(1)
    {
        //清空集合
        FD_ZERO(&readfds); 
        //将要检测的描述符添加到集合中
        FD_SET(fdr, &readfds); 
        FD_SET(STDIN_FILENO, &readfds);
        tmo.tv_sec = 3;
        tmo.tv_nsec = 0;

        ret = pselect(fdmax, &readfds, NULL, NULL, &tmo, NULL);
        //出错的情况
        if (-1 == ret)
        {
            perror("select");  
            break;
        }
        else if (0 == ret)
        {
            printf("3 second time out....\n"); 
            continue;
        }
        else 
        {
            //管道有数据读
            if (FD_ISSET(fdr, &readfds))  
            {
                memset(buf, 0, SIZE); 
                ret = read(fdr, buf, SIZE);
                if (ret <= 0)
                    continue;
                buf[ret] = '\0';
                printf("read from fifo:  %s\n", buf); 
            }

            //标准输入有数据读
            if (FD_ISSET(STDIN_FILENO, &readfds))
            {
                memset(buf, 0, SIZE); 
                ret = read(STDIN_FILENO, buf, SIZE);
                if (ret <= 0)
                    continue;
                buf[ret - 1] = 0; 
                ret = write(fdw, buf, ret);
                if (ret <= 0)
                    perror("write");
            }
        
        }
    }

    close(fdr);
    close(fdw);

    return 0;
err0:
    return -1;
}



