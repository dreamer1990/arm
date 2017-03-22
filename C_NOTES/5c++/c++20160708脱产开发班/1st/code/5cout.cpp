#include <iostream>
using namespace std;



#if 0
    cout是一个对象 不是运算符
	cout语句的一般格式为
	    cout << 表达式1 << 表达式2 << …… << 表达式n;
#endif


int main(void)
{

    //第一种方式
    cout << "This is a C++ program\n";
    cout << "This is a C++ program " << endl;

    //第二种方式
    cout << "This "
         << "is"
         << " a "
         << "C++ "
         << "program"
         << endl;

    //第三种方式
    cout << "This is a ";
    cout << "C++ program";
    cout << endl;


    return 0;
}
