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

//./a.out pid value
int main(int argc, char **argv)
{
    int i = 0;
    pid_t pid = -1;

    s_t s = {
        .a = 1,
        .b = 2,
        .c = 3,
        .d = 'M',
        .name = "uplooking",
    };

    union sigval val;
#if 0
    val.sival_int = 100;

    if (argc == 3)
    {
        val.sival_int = atoi(argv[2]); 
    }

#else
    val.sival_ptr = &s;
    printf("&s = %p\n", &s);
#endif


    printf("pid: %d  \n", getpid());

    //向指定的进程发送信号
    if (sigqueue(atoi(argv[1]), SIGINT, val) == -1)
    {
        perror("sigqueue failed...\n");  
        goto err0;
    }

    return 0;
err0:
    return -1;
}




