#include <stdio.h>
#include <unistd.h>


//int close(int fd);
//fd是文件描述符


int main(void)
{
    int ret = 0;

    //如果文件描述符是非法 则出错返回
    //关闭指定的描述符  释放相关资源
    ret = close(0);
    if (ret < 0)
    {
        perror("close"); 
        goto err0;
    }

    return 0;
err0:
    return -1;
}
