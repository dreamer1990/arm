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

int execve(const char *filename, char *const argv[],
                         char *const envp[]);


#endif

//连个字符指针数组后面以NULL结束
char *const argv[] = {"ls", "/home", (char*)NULL};
char *const envp[] = {"HOME=home", NULL};

int main(void) 
{
    execve("ls", argv, envp);    
    return 0;
}
