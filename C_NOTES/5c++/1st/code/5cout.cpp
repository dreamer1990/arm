#include <iostream>
using namespace std;

/*
 *
 *    cout语句的一般格式为
 *        cout << 表达式1 << 表达式2 << …… << 表达式n;
 *
 */

int main(void)
{
    
    int i = 3;;
    char ch = 'A';
    float f = 3.14;
    double d = 3.1415926;

    //不需要格式控制 自动识别
    cout << "i = " << i << endl;
    cout << "ch = " << int (ch) << endl;
    cout << "ch = " << ch << endl;
    cout << "f = " << f << endl;
    cout << "d = " << d << endl;

    cout << "i = " << i << " ch = "  << ch << endl;

    //输出方式一
    cout << "This is a C++ program...." << endl;
    //输出方式二 可以分多行写 但是后面不能添加逗号或者分号
    cout << "This is "
         << "a C++ "
         << "program...."
         << endl;

    //输出方式三
    cout << "This is ";
    cout << "a C++ ";
    cout << "program....";
    cout << endl;



    return 0;
}
