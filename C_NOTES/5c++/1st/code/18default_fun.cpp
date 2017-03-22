#include <iostream>
using namespace std;


//带默认值的函数
//在定义函数的时候 给形参一个默认值
int fun(int x = 3)
{
    cout << "x = " << x << endl;

    return x;
}

//实参与形参的结合是从左至右顺序进行的。因此指定默认值的参数必须放在形参表列中的最右端，否则出错。
//int fun1(int x, int y = 18, int z)  //错误的情况
int fun1(int x, int y = 18, int z = 19)
{
    cout << "x = " << x << " y = " << y << " z = " << z << endl; 

    return x + y + z;
}

int main(void)
{
    //fun有一个参数 调用的时候 没有传参数 使用默认值
    cout << "main fun ===>  " << fun() << endl;
    //有默认值的函数 也可以指定参数的值 如果没有指定 就使用默认值
    cout << "main fun===>  " << fun(7) << endl;
    
    fun1(1); //x = 1 y = 18 z = 19
    fun1(1, 2); //x = 1 y = 2 z = 19
    fun1(1, 2, 3); //x = 1 y = 2 z = 3

    return 0;
}



