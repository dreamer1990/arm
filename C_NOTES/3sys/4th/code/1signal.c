#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

#if 0
/* Fake signal functions.  */
#define SIG_ERR	((__sighandler_t) -1)		/* Error return.  出错返回*/
#define SIG_DFL	((__sighandler_t) 0)		/* Default action. 默认的动作 */
#define SIG_IGN	((__sighandler_t) 1)		/* Ignore signal.  忽略信号*/
#endif



//sighandler_t signal(int signum, sighandler_t handler);
//signum: 信号编号
//handler： 是信号处理的入口

//信号处理函数  signum是信号的编号
void fun1(int signum)
{
    printf("handle fun1 ...\n"); 
    printf("signum: %d\n", signum);
}

void fun2(int signum)
{
    printf("handle fun2 ...\n"); 
    printf("signum: %d\n", signum);
}

void fun3(int signum)
{
    printf("handle fun3 ...\n"); 
    printf("signum: %d\n", signum);
}



int main(void)
{
    //定义一个函数指针变量
    sighandler_t pret = NULL; 
    
    //Ctrl + c 产生SIGINT信号
    //SIGINT信号处理最开始是默认动作
    //Ctrl + \ 产生SIGQUIT信号
    pret = signal(SIGINT, fun1);
    if (pret == SIG_DFL)
    {
        printf("The SIGINT is default action....\n"); 
    }

    pret = signal(SIGQUIT, fun3);
    if (pret == SIG_DFL)
    {
        printf("The SIGQUIT si default action...\n"); 
    }

    sleep(5);

    //返回之前处理该信号的方式
    pret = signal(SIGINT, fun2);
    if (pret == fun1)
    {
        printf("以前的处理方式是fun1...\n"); 
    }
    
    
    while(1)
        ;
    
    return 0;
}
