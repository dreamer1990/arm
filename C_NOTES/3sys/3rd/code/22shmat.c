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
    key_t key = 0x55;
    char *p = NULL;


    //查看系统共享内存
    //system("ipcs -m");
    //获取共享内存的标志符
    shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0644);
    if (-1 == shmid)
    {
        perror("shmget");  
        goto err0;
    }
    printf("shmid = %d\n", shmid);
    //system("ipcs -m");

    //地址推荐使用NULL 系统自动分配
    //flag 0 表示可以读写的方式
    p = shmat(shmid, NULL, 0);
    if ((void *)-1 == p)
    {
        perror("shmat"); 
        goto err0;
    }
    memset(p, 0, 128);
    memcpy(p, "hello", 5);
    printf("p = %s\n", p);

    //如果有进程与该共享内存没有解除关系 那么其它进程删除该共享内存 就不会立即生效
    //一般建议程序结束后接触关系
    if (shmdt(p) < 0)
    {
        perror("shmdt"); 
        goto err0;
    }
        
    //删除共享内存
    //shmctl(shmid, IPC_RMID, NULL);
    //system("ipcs -m");

    return 0;
err0:
    return -1;
}
