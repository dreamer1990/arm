#include <stdio.h>

    /*
     *int puts(const char *s);
     *功能: 将字符串写入标准输出
     *参数:
     *    s: 指向字符串的指针
     *返回值:
     *    成功 返回非零
     *    失败 返回EOF(-1)
     *    
     */

    /*
     *char *gets(char *s);
     *功能: 从标注输入获取字符串
     *参数:
     *    s: 将获取的字符串保存到s所指向的缓冲区中
     *返回值:
     *    成功: 返回s
     *    失败: 返回NULL
     *注意: gets并不做s越界检查, 因此使用该函数是危险的,建议少用
     *
     */

int main(void)
{
    char buf[32] = "hello world";
    //puts会自动换行 
    puts(buf);

    // warning: the `gets' function is dangerous and should not be used.
    gets(buf);

    //将buf写入标准输出
    puts(buf);

    return 0;
}
