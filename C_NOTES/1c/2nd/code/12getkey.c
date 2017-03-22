#include <stdio.h>

int main(void)
{
    char buf[10];

    //方向键 向上 ESC + [ + A    27  91 65
    //方向键 向下 ESC + [ + B    27  91 66
    //方向键 向右 ESC + [ + C    27  91 67
    //方向键 向左 ESC + [ + D    27  91 68
    
    //从标准输入中获取字符串
    scanf("%s", buf);

    printf("%c  %c  %c\n", buf[0], buf[1], buf[2]);
    printf("%d  %d  %d\n", buf[0], buf[1], buf[2]);

    return 0;
}
