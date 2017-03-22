#include <iostream>
using namespace std;

int main(void)
{

    //endl  代表换行
    cout << "sizeof(short): " << sizeof(short) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;
    cout << "sizeof(char): " << sizeof(char) << endl;
    cout << "sizeof(float): " << sizeof(float) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(long double): " << sizeof(long double) << endl;
    cout << "sizeof(long long): " << sizeof(long long) << endl;
    cout << "sizeof(bool): " << sizeof(bool) << endl;
    // 错误：‘sizeof’ 不能用于 void 类型
    //cout << "sizeof(void): " << sizeof(void) << endl;
    cout << "sizeof(void *): " << sizeof(void *) << endl;



    return 0;
}
