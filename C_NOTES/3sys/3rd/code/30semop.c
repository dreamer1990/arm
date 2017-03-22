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

int main(void)
{
    key_t key = 0x55;

    int semid = -1;
    int ret = -1;
    int i = 0;
    pid_t pid = -1;

    struct sembuf tt = {
        .sem_num = 0,
        .sem_op = -1, // 表示需要占用1个资源
    };

    struct sembuf t1 = {
        .sem_num = 0,
        .sem_op = 0,    //表示当信号量的值为0的时候 就执行
    };

    struct sembuf t2 = {
        .sem_num = 0,
        .sem_op = 10, //释放资源
    };

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
    if (semctl(semid, 0, SETVAL, 10) == -1)
    {
        perror("semctl"); 
        goto err0;
    }
    printf("当前资源为: %d\n", semctl(semid, 0, GETVAL));

    //子进程
    if ((pid = fork()) == 0)
    {
        for (i = 0; i < 55; i++)
        {
            semop(semid, &tt, 1); 
            printf("当前资源为: %d\n", semctl(semid, 0, GETVAL));
            printf("child do workd %d\n", i);
            sleep(1);
        }
    
        exit(0);
    }

    //父进程操作 
    //等待信号号量为0
     semop(semid, &t1, 1); 
     sleep(2);
     printf("parent process awake....\n");
     semop(semid, &t2, 1);

    //第二次给资源
     semop(semid, &t1, 1); 
     sleep(2);
     printf("parent process awake....\n");

    //杀死子进程
    kill(pid, 9); 

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

