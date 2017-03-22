#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#if 0

pid_t ---> int类型

//获取进程ID号
pid_t getpid(void);
//获取当前进程的父进程的ID号
pid_t getppid(void);

uid_t ---> unsigned int类型

//获取当前进程的实际用户ID
uid_t getuid(void);
//获取当前进程的有效用户ID
uid_t geteuid(void);

gid_t ---> unsigned int类型

//返回当前进程的实际用户组
gid_t getgid(void);
//返回当前进程的有效用户组
gid_t getegid(void);



#endif

int main(void)
{

    printf("pid: %d\n",  getpid());
    printf("ppid: %d\n", getppid());

    printf("uid: %u\n",  getuid());
    printf("euid: %u\n", geteuid());

    printf("gid: %u\n", getgid());
    printf("egid: %u\n", getegid());

    return 0;
}





