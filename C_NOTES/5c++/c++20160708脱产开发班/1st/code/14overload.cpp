#include <iostream>

using namespace std;

//函数重载
int max(int x, int y)
{
    return x > y ? x : y;
}

float max(float x, float y)
{
    return x > y ? x : y;
}

double max(double x, double y)
{
    return x > y ? x : y;
}

int main(void)
{
    cout << "max(1, 2): " << max(1, 2) << endl;
    cout << "max(1.1. 1.2): " << max(1.1, 1.2) << endl;
    cout << "max(1.111, 1.2222): " << max(1.111, 1.2222) << endl;

    return 0;
}
