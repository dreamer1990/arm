#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
 *21:守护进程(精灵进程)
 *   步骤:
 *   1.设置创建文件屏蔽字
 *   2.fork产生孤儿进程
 *   3.调用setsid脱离控制终端
 *   4.更改工作路径到'/'
 *   5.关闭不用的文件描述符  并将 stdin stdout stderr 重定向到/dev/null
 */


int main(void)
{
    pid_t pid = -1;
    int ret = 0;


    //创建一个子进程
    pid = fork();
    if (pid < 0)
    {
        perror("fork"); 
        goto err0;
    }

    //父进程退出
    if (0 != pid)
        exit(0);

    //调用setsid脱离控制终端
    setsid();

    //更改工作目录到/
    ret = chdir("/");
    if (ret < 0)
    {
        perror("chdir"); 
        goto err0;
    }

    //设置创建文件的屏蔽字
    umask(0); 
    //关闭标准输入 标准输出 标准出错
    close(0);
    close(1);
    close(2);

    while(1)
    {
        system("echo \"hello world\" >>/var/log/hello.log");
    
        sleep(2); 
    }



    return 0;
err0:
    return -1;
}



