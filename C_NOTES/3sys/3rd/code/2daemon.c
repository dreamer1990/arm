#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
    int ret = 0; 
    
    //调用系统调用创建一个精灵进程
    ret = daemon(0, 0);
    if (ret < 0)
    {
        perror("daemon"); 
        goto err0;
    }

    //守护进程工作
    while(1)
    {
        system("echo \"hello world\" >> /var/log/test.log");

        sleep(2);
    }



    return 0;
err0:
    return -1;
}
