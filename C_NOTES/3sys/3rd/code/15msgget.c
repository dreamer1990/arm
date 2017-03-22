#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//key_t  int

int main(void)
{
    key_t key = 0x55;
    int msgid = -1;


    //返回消息队类的标志符
    msgid = msgget(key, IPC_CREAT | 0644);
    if (-1 == msgid)
    {
        perror("msgget"); 
        goto err0;
    }

    system("ipcs -q");   
    printf("key = %#x msgid = %d\n", key, msgid);
    printf("==========================\n");
 
    //返回消息队类的标志符
    msgid = msgget(key, IPC_CREAT | 0666);
    if (-1 == msgid)
    {
        perror("msgget"); 
        goto err0;
    }

    printf("key = %#x msgid = %d\n", key, msgid);

    system("ipcs -q");   
    printf("==========================\n");
   
    
     //返回消息队类的标志符
    //msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0644);
    msgid = msgget(key, 0);
    if (-1 == msgid)
    {
        perror("msgget"); 
        goto err0;
    }

    printf("key = %#x msgid = %d\n", key, msgid);

    //删除系统中指定的消息队列
    if (msgctl(msgid, IPC_RMID, NULL) < 0)
    {
        perror("msgctl"); 
        goto err0;
    }
    return 0;
err0:
    return -1;
}




