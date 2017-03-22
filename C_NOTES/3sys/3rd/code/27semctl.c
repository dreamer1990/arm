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

    //清零
    memset(&ds, 0, sizeof(ds));
    //第二个参数被忽略
    ret = semctl(semid, 0, IPC_STAT, &ds);
    if (-1 == ret)
    {
        perror("semctl"); 
        goto err0;
    }
    show_sem(&ds);

    //改变信息
    ds.sem_perm.mode = 0666;
    //改变不了信号量的个数
    ds.sem_nsems = 10;
    //第二个参数被忽略
    if (semctl(semid, 0, IPC_SET, &ds) == -1)
    {
        perror("semctl"); 
        goto err0;
    }
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

