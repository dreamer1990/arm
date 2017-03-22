#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

//PAGE_SIZE 0x400  --> 1K

#define SIZE 256


int main(void)
{
    int ret = -1;
    int shmid = -1;
    pid_t pid = -1;
    char *p = NULL;
    char buf[SIZE];
    key_t key = 0x55;


    //查看系统共享内存
    //system("ipcs -m");
    //获取共享内存的标志符
    shmid = shmget(key, SIZE, IPC_CREAT | 0644);
    if (-1 == shmid)
    {
        perror("shmget");  
        goto err0;
    }
    printf("shmid = %d\n", shmid);
    
    //建立映射关系 只读
    p = shmat(shmid, NULL, 0);
    if ((void *)-1 == p)
    {
        perror("shmat"); 
        goto err0;
    }

    //创建一个子进程
    pid = fork();
    if (pid == 0)
    {
        //清零
        memset(p, 0, SIZE);
        memcpy(p, "hello child", strlen("hello child"));
        printf("child process exit....\n"); 
        ret = shmdt(p);
        if (-1 == ret)
        {
            perror("shmdt"); 
        }
        exit(0); 
    }
    //等待子进程运行结束
    wait(NULL);    

    printf("p = %s\n", p);

    //父进程
    ret = shmdt(p);
    if (-1 == ret)
    {
        perror("shmdt"); 
        goto err0;
    }

    return 0;
err0:
    return -1;
}
