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

    msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0644);
    if (msgid < 0)
    {
        perror("msgget"); 
        goto err0;
    }

    sleep(5);

    //查看消息队列
    ret = msgctl(msgid, IPC_STAT, &buf);
    if (ret < 0)
    {
        perror("msgctl"); 
        goto err0;
    }

    printf("num: %d\n", buf.msg_qnum);
    printf("bytes: %d\n", buf.msg_qbytes);
    printf("lspid: %d\n", buf.msg_lspid);
    printf("lrpid: %d\n", buf.msg_lrpid);

    

    return 0;
err0:
    return -1;
}

