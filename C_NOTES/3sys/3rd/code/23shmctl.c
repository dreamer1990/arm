#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

//PAGE_SIZE 0x400  --> 1K

#if 0
/* Obsolete, used only for backwards compatibility and libc5 compiles */
struct shmid_ds {
	struct ipc_perm		shm_perm;	/* operation perms */
	int			shm_segsz;	/* size of segment (bytes) */
	__kernel_time_t		shm_atime;	/* last attach time */
	__kernel_time_t		shm_dtime;	/* last detach time */
	__kernel_time_t		shm_ctime;	/* last change time */
	__kernel_ipc_pid_t	shm_cpid;	/* pid of creator */
	__kernel_ipc_pid_t	shm_lpid;	/* pid of last operator */
	unsigned short		shm_nattch;	/* no. of current attaches */
	unsigned short 		shm_unused;	/* compatibility */
	void 			*shm_unused2;	/* ditto - used by DIPC */
	void			*shm_unused3;	/* unused */
};
#endif

#define SIZE 256

//显示信息
void shm_show(struct shmid_ds *p)
{
    printf("atime: %ld  dtime: %ld  ctime: %ld\n", p->shm_atime, p->shm_dtime, p->shm_ctime);
    printf("cpid: %d  lpid: %d\n", p->shm_cpid, p->shm_lpid);
}

int main(void)
{
    int ret = -1;
    int shmid = -1;
    char *p = NULL;
    key_t key = 0x55;
    struct shmid_ds ds;


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
    //system("ipcs -m");
    
    memset(&ds, 0, sizeof(ds));
    //获取共享内存的信息
    ret = shmctl(shmid, IPC_STAT, &ds);
    if (-1 == ret)
    {
        perror("shmctl");  
        goto err0;
    }

    shm_show(&ds);
    printf("=======================\n");
    ds.shm_perm.mode = 0666;
    //更改共享内存的信息
    ret = shmctl(shmid, IPC_SET, &ds);
    if (-1 == ret)
    {
        perror("shmctl"); 
        goto err0;
    }

    system("ipcs -m");

    //删除共享内存
    ret = shmctl(shmid, IPC_RMID, NULL);
    if (ret == -1)
    {
        perror("shmctl"); 
        goto err0;
    }

    return 0;
err0:
    return -1;
}
