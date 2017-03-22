#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUM 5


#if 0
/* Obsolete, used only for backwards compatibility and libc5 compiles */
struct semid_ds {
	struct ipc_perm	sem_perm;		/* permissions .. see ipc.h */
	__kernel_time_t	sem_otime;		/* last semop time */
	__kernel_time_t	sem_ctime;		/* last change time */
	struct sem	*sem_base;		/* ptr to first semaphore in array */
	struct sem_queue *sem_pending;		/* pending operations to be processed */
	struct sem_queue **sem_pending_last;	/* last pending operation */
	struct sem_undo	*undo;			/* undo requests on this array */
	unsigned short	sem_nsems;		/* no. of semaphores in array */ //信号量个数
};
#endif


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
    struct semid_ds ds;

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

    //给信号量赋值
    for (i = 0; i < NUM; i++)
    {   //设置第i个信号量的值
        if (semctl(semid, i, SETVAL, i + 1) == -1) 
        {
            perror("semct"); 
            break;
        }
    }

    //读出每个信号量的值
    for (i = 0; i < NUM; i++)
    {
        printf("第%d个信号量的资源数为 %d\n", i, semctl(semid, i, GETVAL)); 
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

