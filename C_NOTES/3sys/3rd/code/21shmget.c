#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

//PAGE_SIZE 0x400  --> 1K



int main(void)
{
    int ret = -1;
    int shmid = -1;
    key_t key = 0x55;

    //查看系统共享内存
    system("ipcs -m");
    //获取共享内存的标志符
    shmid = shmget(key, 1, IPC_CREAT | IPC_EXCL | 0644);
    if (-1 == shmid)
    {
        perror("shmget");  
        goto err0;
    }

    printf("shmid = %d\n", shmid);
    system("ipcs -m");

    
    //删除共享内存
    shmctl(shmid, IPC_RMID, NULL);
    system("ipcs -m");

    return 0;
err0:
    return -1;
}
