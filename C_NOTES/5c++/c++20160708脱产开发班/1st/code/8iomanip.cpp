#include <iostream>
#include <iomanip>
using namespace std;


int main(void)
{
    double a = 31415926.79288;
    int b = 123456;

    //默认格式输出
    cout << a << endl;
    //设置数字的个数
    cout << setprecision(9) << a << endl;
    cout << setprecision(6) << a << endl;
    cout << setiosflags(ios::fixed) << a << endl;
    cout << setiosflags(ios::fixed) << setprecision(9) << a << endl;
    cout << setiosflags(ios::scientific) << a << endl;
    cout << setiosflags(ios::scientific) << setprecision(4) << a << endl;


    cout << "====================" << endl;
    //整型
    cout << b << endl;
    cout << hex << b << endl;
    cout << oct << b << endl;
    cout << dec << b << endl;
    cout << hex << setiosflags(ios::uppercase) << b << endl;
    cout << setfill('*') << setw(10) << b << endl;
    cout << dec << setiosflags(ios::showpos) << b << endl;


    return 0;
}
