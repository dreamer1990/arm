#include <iostream>
using namespace std;

//重载 函数名一样 功能类似 
//参数类型一样 但是参数个数不一样

int max(int x, int y)
{
    return x > y ? x : y;
}
//重载不能是参数类型和个数一模一样 只是返回值类型不一样
//long max(int x, int y)
//{
//   return long(x > y ? x : y);
//}

int max(int x, int y, int z)
{
    return  x > y ? (x > z ? x : z) : (y > z ? y : z);
}

long max(long x, long y)
{
    return x > y ? x : y;
}

int main(void)
{
    int x = 3;
    int y = 4;
    int z = 5;

    long l1 = 33, l2 = 44;

    cout << "max(x, y) = " << max(x, y) << endl;
    cout << "max(x, y, z) = " << max(x, y, z) << endl;

    cout << "max(l1, l2) = " << max(l1, l2) << endl;

    return 0;
}
