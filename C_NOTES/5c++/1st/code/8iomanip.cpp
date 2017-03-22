#include <iostream>
#include <iomanip>
using namespace std;


    /*
     *double a = 123.456789012345; //对a赋初值
     *(1) cout << a; 输出： 123.456  
     *(2) cout << setprecision(9) << a; 输出： 123.456789  
     *(3) cout << setprecision(6); 恢复默认格式(精度为6)
     *(4) cout <<  setiosflags(ios∷fixed); 输出： 123.456789
     *(5) cout << setiosflags(ios∷fixed) << setprecision(8) << a; 输出： 123.45678901
     *(6) cout << setiosflags(ios∷scientific) << a; 输出： 1.234568e+02
     *(7) cout << setiosflags(ios∷scientific) << setprecision(4) << a; 输出： 1.2346e02
     *下面是整数输出的例子： 
     *int b = 123456;对b赋初值
     *(1) cout << b;输出： 123456
     *(2) cout << hex << b; 输出： 1e240     
     *(3) cout << setiosflags(ios∷uppercase) << b;输出： 1E240     
     *(4) cout << setw(10) << b << ′,′ << b; 输出：     123456，123456
     *(5) cout << setfill(′*′) << setw(10) << b;输出： **** 123456
     *(6) cout << setiosflags(ios∷showpos) << b;输出： +123456
     *
     */

int main(void)
{
    double d = 123.456789012345;
    int b = 123456;

    //双精度的例子
    //使用默认格式
    cout << d << endl;
    cout << setprecision(9) << d << endl;
    cout << setprecision(6) << d << endl;
    cout << setiosflags(ios::fixed) << d << endl;
    cout << setiosflags(ios::fixed) << setprecision(8) << d << endl;
    cout << setiosflags(ios::scientific) << d << endl;
    cout << setiosflags(ios::scientific) << setprecision(4) << d << endl;

    //整型
    cout << b << endl;
    //以十六进制输出
    cout << hex << b << endl;
    //以八进制输出
    cout << oct << b << endl;
    //以十进制输出
    cout << dec << b << endl;
    cout << setiosflags(ios::uppercase) << hex << b << endl;
    cout << setw(10) << b << "*" << b << endl;
    cout << setfill('#') << setw(10) << b << "*" << b << endl;
    cout << setiosflags(ios::showpos) << dec <<  b << endl;
    return 0;
}
