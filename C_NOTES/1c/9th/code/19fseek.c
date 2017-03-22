#include <stdio.h>

int main(void)
{
    int ret;
    
    //标准输入 标准输出 标准出错是不能被fseek  ftell rewind
    //返回-1  
    ret = ftell(stdin);
    printf("ret = %d\n", ret);

    //-1
    ret = fseek(stdin, 0L, SEEK_END);
    printf("fseek stdin:  %d\n", ret);

    //rewind(stdin);

    return 0;
}
