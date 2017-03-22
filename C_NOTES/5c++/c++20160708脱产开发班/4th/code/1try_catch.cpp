#include <iostream>

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
    if (0 == y)
    {
        throw  y;
    }

    return x / y;
}

int main(void)
{
    int x, y;

    cin >> x >> y;

    try{
        cout << "x / y = "  << myDiv(x, y) << endl;
    }
    catch(int y)
    {
        cout << "The y is 0"  << endl;
    }

    return 0;
}
