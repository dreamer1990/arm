#include <iostream>

using namespace std;

//重载必须是形参类型或者形参个数不一致
//不能是返回类型不一致 而行参都一模一样

int max(int x, int y)
{
    return x > y ? x : y;
}

#if 0
double max(int x, int y)
{
    return double (x > y ? x : y);
}
#endif


int main(void)
{
    cout << "max(1, 3): " << max(1, 3) << endl;

    return 0;
}
