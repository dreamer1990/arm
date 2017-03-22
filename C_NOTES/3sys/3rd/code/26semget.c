#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUM 5

int main(void)
{
    key_t key = 0x55;

    int semid = -1;

    //创建信号量集
    semid = semget(key, NUM, IPC_CREAT | 0644);
    if (-1 == semid)
    {
        perror("semget"); 
        goto err0;
    }
    printf("semid = %d\n", semid);

    //查看系统的信号量
    system("ipcs -s");


    getchar();
    //删除信号量 第二个参数被忽略  
    if (semctl(semid, 0, IPC_RMID, NULL) == -1) 
    {
        perror("semctl"); 
        goto err0;
    }

    system("ipcs -s");

    return 0;
err0:
    return -1;
}

