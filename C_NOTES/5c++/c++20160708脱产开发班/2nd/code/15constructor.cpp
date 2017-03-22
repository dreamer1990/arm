#include <iostream>

using namespace std;


#if 0
	为了解决这个问题，C++提供了构造函数(constructor)来处理对象的初始化。构造函数是一种特殊的成员函数，与其他成员函数不同，不需要用户来调用它，
	而是在建立对象时自动执行。构造函数的名字必须与类名同名，而不能由用户任意命名，以便编译系统能识别它并把它作为构造函数处理。它不具有任何类型，
	不返回任何值。构造函数的功能是由用户定义的，用户根据初始化的要求设计函数体和函数参数。

	有关构造函数的使用，有以下说明： 
	(1) 在类对象进入其作用域时调用构造函数。
	(2) 构造函数没有返回值，因此也不需要在定义构造函数时声明类型，这是它和一般函数的一个重要的不同之点。
	(3) 构造函数不需用户调用，也不能被用户调用。
	(4) 在构造函数的函数体中不仅可以对数据成员赋初值，而且可以包含其他语句。但是一般不提倡在构造函数中加入与初始化无关的内容，以保持程序的清晰。
	(5) 如果用户自己没有定义构造函数，则C++系统会自动生成一个构造函数，只是这个构造函数的函数体是空的，也没有参数，不执行初始化操作。


#endif

class Time{
public:
    //构造函数
    Time(void);
    void setTime(int, int, int);
    void showTime(void);

private:
    int hour;
    int min;
    int sec;
};

//构造函数的定义
Time::Time(void)
{
    hour = 0;
    min = 0;
    sec = 0;
    cout << "constructor....." << endl;
}

void Time::setTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}

void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
}

int main(void)
{
    Time t;
    Time t2;

    t.showTime();

    t2.setTime(12, 12 ,12);
    t2.showTime();

    return 0;
}










