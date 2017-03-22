#include <iostream>
using namespace std;

/*
 *
 *    cin语句的一般格式为
 *    	cin >> 变量1 >> 变量2 >> …… >> 变量n;
 *
 */

int main(void)
{

    int a, b, c;

    //输入三个整型 cin遇到空格或者换行 制表符就认为结束
    cin >> a >> b >> c;
    //输出
    cout << a << " " << b << " " << c << endl;

    //cin的第二种方式
    cin >> a
        >> b
        >> c;
    cout << a << " " << b << " " << c << endl;

    //cin的第三种方式
    cin >> a;
    cin >> b;
    cin >> c;
    cout << a << " " << b << " " << c << endl;

    return 0;
}
