#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main(void)
{
    int ret = 0;
    key_t key = -1;
    int msgid = -1;

    struct msqid_ds buf;

    //创建key
    key = ftok("a.out", 0x5);
    if (key < 0)
    {
        perror("ftok"); 
        goto err0;
    }

    printf("key = %d\n", key);

    //IPC_CREATE 创建
    //IPC_EXCL 如果指定key存在 就会报错
    //0644 权限
    msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0644);
    if (msgid < 0)
    {
        perror("msgget"); 
        goto err0;
    }

    sleep(5);

    //删除消息队列
    ret = msgctl(msgid, IPC_RMID, NULL);
    if (ret < 0)
    {
        perror("msgctl"); 
    }
    

    return 0;
err0:
    return -1;
}

