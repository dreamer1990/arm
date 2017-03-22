#include <stdio.h>
//#include "a.h"
#include "a.h"
//错误：a.h：没有那个文件或目录
//#include <a.h>

#include "a.h"


    /*
	 *<>:只会从系统头文件目录中查找
	 *"":先从当前工作目录中查找，如果当前工作目录中不存在，则从系统头文件目录中查找
	 *
     */

int main(void)
{
    int a = 3;
    int b = 4;

    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b)); 
    printf("a * b = %d\n", mul(a, b));
    printf("a / b = %d\n", div(a, b));


    return 0;
}
