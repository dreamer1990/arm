#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUM 1


//查看信号量的信息
void show_sem(struct semid_ds *p)
{
   printf("otime: %ld ctime: %ld nsems: %hu\n", p->sem_otime, p->sem_ctime, p->sem_nsems); 
}

//获取资源
void sem_p(int semid)
{
    struct sembuf tt = {
        .sem_num = 0,
        .sem_op = -1,
    };
    semop(semid, &tt, 1);
}
//释放资源
void sem_v(int semid)
{
    struct sembuf tt = {
        .sem_num = 0,
        .sem_op = 1,
    };
    semop(semid, &tt, 1); 
}

int main(void)
{
    key_t key = 0x55;

    int semid = -1;
    int ret = -1;
    int i = 0;
    pid_t pid = -1;

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
    if (semctl(semid, 0, SETVAL, 4) == -1)
    {
        perror("semctl"); 
        goto err0;
    }
    printf("当前资源为: %d\n", semctl(semid, 0, GETVAL));

    for (i = 0; i < 20; i++)
    {
        pid = fork(); 
        if (0 == pid)
        {
            sem_p(semid);  
            printf("child process %d\n", i);
            sleep(2);
            sem_v(semid);
            exit(0);
        }
    }


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

