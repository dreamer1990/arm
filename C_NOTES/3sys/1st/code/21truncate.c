#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    
    int ret = 0;

    //将文件截短为10个字节
    ret = truncate("txt", 10);
    if (ret < 0)
    {
        perror("truncate"); 
    }

    return 0;
}
