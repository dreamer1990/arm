#include <iostream>
#include <string.h>

using namespace std;



#if 0
	throw语句一般是由throw运算符和一个数据组成的，其形式为
	throw 表达式;
	try-catch的结构为
	try
	      {被检查的语句} 
	catch(异常信息类型 [变量名])
	      {进行异常处理的语句}
#endif

int myDiv(int x, int y)
{
    string s = "the divide is 0";
    if (0 == y)
    {
        //抛出异常
        throw s; 
    }

    return x / y;
}

int main(void)
{
    int x, y;

    cin >> x >> y;

    //检查异常
    try{
        cout << "x / y = "  << myDiv(x, y) << endl;
    }
    catch(int y)
    {
        cout << "The y is 0"  << endl;
    }
    //捕获异常
    catch(string msg)
    {
        cout << msg << endl;
    }

    return 0;
}
