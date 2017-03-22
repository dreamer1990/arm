#include <iostream>

using namespace std;

/*
 *
 *    (2) 一个函数不仅既作为重载函数，又作为有默认参数的函数。因为当调用函数时如果少写一个参数，系统无法判定是利用重载函数还是利用默认参数的函数，出现二义性，系统无法执行。
 *    
 *
 */


#if 0
//带有默认参数的函数
int fun(int x, int y = 20, int z = 10)
{
    cout << "x + y + z = " << x + y + z << endl;
}
#endif

//是函数重载
int fun(int x, int y, int z)
{
    cout << "x + y + z = " << x + y + z << endl;
}

int fun(int x, int y)
{
    cout << "x + y = " << x + y << endl;
}



int main(void)
{
    fun(10, 20);
    
    return 0;
}
