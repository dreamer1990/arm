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


int main(void)
{
    int ret = -1;
    int shmid = -1;
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
    p = shmat(shmid, NULL, SHM_RDONLY);
    //p = shmat(shmid, NULL, 0);
    if ((void *)-1 == p)
    {
        perror("shmat"); 
        goto err0;
    }
    //如果是只读的方式 以下语句出现段错误
    //memcpy(p, "hello", 5);
    
    memcpy(buf, p, SIZE);
    printf("buf: %s\n", buf);

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
