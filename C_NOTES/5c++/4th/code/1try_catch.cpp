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

// x / y
int div(int x, int y)
{
    if (0 == y) 
        //抛出异常
        throw y;
    
    return x / y;
}

int main(void)
{
    int x, y;
    int result;

    cin >> x >> y;

    //检查相应代码段是否有异常
    try
    {
        result = div(x, y); 
    }
    //捕获异常
    catch (int)
    {
        cout << "The y is equal 0 error.."  << endl;
    }
    catch (double)
    {
        cout << "error"  << endl;
    }

    return 0;
}
