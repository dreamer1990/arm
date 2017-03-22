#include <iostream>

using namespace std;


int add2(int x, int y)
{
    long i = 0;

    for (i = 0; i < 100000; i++)
    {
        cout << "3 + 4 = "  << 3 + 4 << endl;
    }
    
    return 0;
}
int add(int x, int y)
{
    return x + y;
}

inline int add1(int x, int y)
{
    return x + y;
}

int main(void)
{
    long i = 0;
    
    add2(3, 4);

    return 0;
}
