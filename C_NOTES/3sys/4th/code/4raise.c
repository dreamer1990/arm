#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 *int raise(int sig)
 *功能: 向调用者发送一个信号
 *参数:
 *    sig  信号
 *返回值:
 *    成功: 0
 *    失败: 非零
 *与kill(getpid(), sig)等价
 */

int main(void)
{
    int i = 0;
    int ret = 0;

    while(1)
    {
        printf("do work %d\n", i++); 
        sleep(1);

        if (4 == i)
        {
            //给自己发送信号
            ret = raise(SIGINT); 
            if (ret != 0)
            {
                perror("raise"); 
                break;
            }
        }
        
    }



    return 0;
}
