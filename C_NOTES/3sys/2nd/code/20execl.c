#include <stdio.h>
#include <unistd.h>

#if 0
extern char **environ;

int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg,
        ..., char * const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);

#endif

char *const argv[] = {"ls", "/home", (char*)NULL};
char *const envp[] = {"HOME=home", NULL};

int main(void) 
{

#if 0
    execl("/bin/ls", "ls", "/home", (char*)NULL); 


    execv("/bin/ls", argv);

    //第一个参数一定是当前目录
    execlp("ls", "ls", "/home", (char*)NULL);

    execle("/bin/ls", "ls", "/home", (char*)NULL, envp);
#endif
    execvp("ls", argv);

    return 0;
}
