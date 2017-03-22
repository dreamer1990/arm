#include <stdio.h>
#include <stdlib.h>

#if 0
//设置环境变量
int setenv(const char *name, const char *value, int overwrite);
//取消环境变量
int unsetenv(const char *name);
//获取环境变量的值
char *getenv(const char *name)；
#endif


int main(void)
{
    int ret = 0;

    //获取环境变量
    printf("$HOME = %s\n", getenv("HOME"));

    //设置自己的环境变量 

    
    //设置环境变量UPLOOK="hello uplooking"
    ret = setenv("UPLOOK", "hello uplooking", 1);
    if (ret < 0)
    {
        perror("setenv"); 
        goto err0;
    }
    //获取环境变量
    printf("$UPLOOK=%s\n", getenv("UPLOOK"));

    //取消设置的环境变量
    if (unsetenv("UPLOOK") < 0)
    {
        perror("unsetenv"); 
        goto err0;
    }

    printf("$UPLOOK=%s\n", getenv("UPLOOK"));

    return 0;
err0:
    return -1;
}













