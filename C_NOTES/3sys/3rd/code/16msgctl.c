
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//key_t  int


#if 0
/* Obsolete, used only for backwards compatibility and libc5 compiles */
struct msqid_ds {
	struct ipc_perm msg_perm;
	struct msg *msg_first;		/* first message on queue,unused  */
	struct msg *msg_last;		/* last message in queue,unused */
	__kernel_time_t msg_stime;	/* last msgsnd time */
	__kernel_time_t msg_rtime;	/* last msgrcv time */
	__kernel_time_t msg_ctime;	/* last change time */
	unsigned long  msg_lcbytes;	/* Reuse junk fields for 32 bit */
	unsigned long  msg_lqbytes;	/* ditto */
	unsigned short msg_cbytes;	/* current number of bytes on queue */
	unsigned short msg_qnum;	/* number of messages in queue */
	unsigned short msg_qbytes;	/* max number of bytes on queue */
	__kernel_ipc_pid_t msg_lspid;	/* pid of last msgsnd */
	__kernel_ipc_pid_t msg_lrpid;	/* last receive pid */
};

#endif

void msg_info(struct msqid_ds *ds)
{
    printf("==========================info====================\n");
    //最后发送消息的时候  最后接收消息的时间 最后改变消息队列的时间
    printf("stime: %ld rtime: %ld ctime: %ld\n", ds->msg_stime, ds->msg_rtime, ds->msg_ctime);
    //当前消息队列中消息的字节数 消息的个数 最大消息所占字节数
    printf("cbytes: %u  qnum: %u qbytes: %u\n", ds->msg_cbytes, ds->msg_qnum, ds->msg_qbytes);
    //最后发送消息的PID  最后接收消息的PID
    printf("lspid: %d  lrpid: %d\n", ds->msg_lspid, ds->msg_lrpid);
    printf("==========================end====================\n");
}

int main(void)
{

    int ret = -1;
    int msgid = -1;
    key_t  key = 0x55;
    struct msqid_ds msg_ds;

    //默认0 如果消息队列不存在  默认不能创建该消息队列
    //msgid = msgget(key, 0); 
    //创建一个新的队列或者打开一个现存的消息队列
    msgid = msgget(key, IPC_CREAT | 0644); 
    if (-1 == msgid)
    {
        perror("msgid"); 
        goto err0;
    }
    system("ipcs -q");

    memset(&msg_ds, 0, sizeof(msg_ds));
    //获取消息队列相关的信息
    ret = msgctl(msgid, IPC_STAT, &msg_ds);
    if (ret < 0)
    {
        perror("msgctl"); 
        goto err0;
    }
    
    //查看消息队列的信息
    msg_info(&msg_ds);

    //更改消息队列的信息
    //0666 八进制
    msg_ds.msg_perm.mode = 0666;
    ret = msgctl(msgid, IPC_SET, &msg_ds);
    if (ret < 0)
    {
        perror("msgctl"); 
        goto err0;
    }
    system("ipcs -q");

    getchar();
    printf("===========================\n");
    //删除消息队列
    ret = msgctl(msgid, IPC_RMID, NULL);
    if (ret < 0)
    {
        perror("msgctl");
        goto err0;
    }

    system("ipcs -q");

    return 0;
err0:
    return -1;
}





