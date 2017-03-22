#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>



int main(void)
{
    int fd = -1;


    //一般不使用creat这个API 
    //如果文件存在 则不创建该文件  而是直接以只写的方式打开
    //fd = open("txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);等价
    fd = creat("txt", 0644);
    if (fd < 0)
    {
        //输出出错的原因
        perror("creat"); 
        goto err0;
    }

    printf("fd = %d\n", fd);

    //关闭指定的文件
    close(fd);
    //形参的改变 并不能直接改变实参
    printf("关闭之后:  fd = %d\n", fd);

    return 0;
err0:
    return -1;
}
