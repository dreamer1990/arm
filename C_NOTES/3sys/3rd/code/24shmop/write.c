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
    
    //建立映射关系 读写
    p = shmat(shmid, NULL, 0);
    if ((void *)-1 == p)
    {
        perror("shmat"); 
        goto err0;
    }

    memcpy(p, "hello uplooking", strlen("hello uplooking"));

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
