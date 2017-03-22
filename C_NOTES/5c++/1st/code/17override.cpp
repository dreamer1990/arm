#include <iostream>
using namespace std;


//函数模板
template <typename T1>
T1 fun(T1 x, T1 y)
{
    cout << "==============fun ==========" << endl;
    return x + y;
}

//函数重载
int fun(int x, int y)
{
    return x + y;
}

long fun(long x, long y)
{
    return x + y;
}


int main(void)
{
    int i1 =33, i2 = 44;
    long l1 = 333, l2 = 444;
    //当模板和重载冲突的时候  就优先调用重载
    cout << "fun(i1, i2) = " << fun(i1, i2) << endl;

    return 0;
}

