#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


typedef struct _s_t{
    int a;
    int b;
    int c;
    char d;
    char name[32];
}s_t;

#if 0

typedef union sigval {
    int sival_int; //整型的数据
    void *sival_ptr; //指针
} sigval_t;


siginfo_t {
    int      si_signo;    /* Signal number */ 信号的编号
        int      si_errno;    /* An errno value */
    int      si_code;     /* Signal code */
    int      si_trapno;   /* Trap number that caused
                             hardware-generated signal
                             (unused on most architectures) */
    pid_t    si_pid;      /* Sending process ID */  发送信号的进程ID号
        uid_t    si_uid;      /* Real user ID of sending process */ 
    int      si_status;   /* Exit value or signal */
    clock_t  si_utime;    /* User time consumed */
    clock_t  si_stime;    /* System time consumed */
    sigval_t si_value;    /* Signal value */    //数据
    int      si_int;      /* POSIX.1b signal */
    void    *si_ptr;      /* POSIX.1b signal */
    int      si_overrun;  /* Timer overrun count; POSIX.1b timers */
    int      si_timerid;  /* Timer ID; POSIX.1b timers */
    void    *si_addr;   
#endif


    void fun(int signum, siginfo_t * siginfo, void * text)
    {
        s_t *p = NULL;

        printf("接收到的信号为： %d\n", signum);
        printf("si_signo: %d\n", siginfo->si_signo);
        printf("si_pid: %d\n", siginfo->si_pid);
#if 0
        printf("si_value: %d\n", siginfo->si_value.sival_int);
        printf("si_int: %d\n", siginfo->si_int);
#else
        //仅仅发送指针的值 如果驱打印值 出现段错误
        p = siginfo->si_value.sival_ptr; 
        printf("p = %p\n", p);
        //printf("a: %d b: %d c: %d d: %c name: %s\n", p->a, p->b, p->c, p->d, p->name);
#endif
    }



    int main(void)
    {

        //等价于signal
        //结构体变量
        struct sigaction act, oact;

        //信号操作函数
        act.sa_sigaction = fun;
        //清空阻塞集
        sigemptyset(&act.sa_mask);
        act.sa_flags = SA_SIGINFO;

        printf("pid: %d\n", getpid());

        if (sigaction(SIGINT, &act, &oact) == -1)
        {
            perror("sigaction"); 
            goto err0;
        }

        if (sigaction(SIGQUIT, &act, &oact) == -1)
        {
            perror("sigaction"); 
            goto err0;
        }

        pause();
        pause();

        return 0;
err0:
        return -1;
    }



