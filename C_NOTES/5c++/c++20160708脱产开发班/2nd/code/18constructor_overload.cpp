#include <iostream>

using namespace std;


#if 0
 8.5 构造函数的重载

	在一个类中可以定义多个构造函数，以便对类对象提供不同的初始化的方法，供用户选用。
	这些构造函数具有相同的名字，而参数的个数或参数的类型不相同。这称为构造函数的重载

	说明： 
	(1) 调用构造函数时不必给出实参的构造函数，称为默认构造函数(default constructor)。
	显然，无参的构造函数属于默认构造函数。一个类只能有一个默认构造函数。
	(2) 如果在建立对象时选用的是无参构造函数，应注意正确书写定义对象的语句。
	(3) 尽管在一个类中可以包含多个构造函数，但是对于每一个对象来说，
	建立对象时只执行其中一个构造函数，并非每个构造函数都被执行。

#endif


class Time{
public:
    //构造函数重载
    Time(void);
    Time(int);
    Time(int, int);
    Time(int, int, int);
    void setTime(int, int, int);
    void showTime(void);

private:
    int hour;
    int min;
    int sec;
};

//默认构造函数
Time::Time(void)
{
    hour = 0;
    min = 0;
    sec = 0;
    cout << "empty contructor" << endl;
}

Time::Time(int h)
{
    hour = h;
    min = 0;
    sec = 0;

    cout << "int constructor" << endl;
}

Time::Time(int h, int m)
{
    hour = h;
    min = m;
    sec = 0;

    cout << "int int constructor." << endl;

}

//参数初始化表来实现对数据成员进行初始化
//构造函数的定义
Time::Time(int h, int m, int s):hour(h), min(m), sec(s)
{
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
    Time t1;

    Time t2(1);

    Time t3(11, 11);

    Time t4(12, 12, 12);

    t1.showTime();
    t2.showTime();
    t3.showTime();
    t4.showTime();

    return 0;
}










