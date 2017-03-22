#include <iostream>
using namespace std;



/*
 *1. 使用循环输出九九乘法表
 *   1*1=1
 *   1*2=2 2*2=4
 *   ......
 *
 */

int main(void)
{
    int i = 0;
    int j = 0;

    //控制输出多少行
    for (i = 1; i < 10; i++)
    {
        //控制一行的输出
        for (j = 1; j <= i; j++) 
        {
            cout << j << "*" << i << "=" << i * j << " ";
        }
        //换行
        cout << endl;
    }

    return 0;
}
