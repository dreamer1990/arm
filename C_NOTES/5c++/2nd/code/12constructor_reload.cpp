#include <iostream>
using namespace std;


/*
 * 8.5 构造函数的重载
 *
 *    在一个类中可以定义多个构造函数，以便对类对象提供不同的初始化的方法，供用户选用。这些构造函数具有相同的名字，而参数的个数或参数的类型不相同。这称为构造函数的重载
 *
 *    说明： 
 *    (1) 调用构造函数时不必给出实参的构造函数，称为默认构造函数(default constructor)。显然，无参的构造函数属于默认构造函数。一个类只能有一个默认构造函数。
 *    (2) 如果在建立对象时选用的是无参构造函数，应注意正确书写定义对象的语句。
 *    (3) 尽管在一个类中可以包含多个构造函数，但是对于每一个对象来说，建立对象时只执行其中一个构造函数，并非每个构造函数都被执行。
 *
 */

//类的声明
class Time{
//私有
private:
    int hour;
    int min;
    int sec;

public:
    void setTime(int _h, int _m, int _s);
    void showTime(void);
    //构造函数重载
    Time(void);
    Time(int );
    Time(int , int );
    Time(int , int , int );
};

//使用参数初始化表 对数据成员初始化
Time::Time(int h, int s, int m):hour(h), min(m), sec(s){}
Time::Time(int h):hour(h){min = 0; sec = 0;}
Time::Time(int h, int m):hour(h), min(m){sec = 0;}

//类的成员函数的定义
void Time::setTime(int _h, int _m, int _s)
{
    hour = _h;
    min = _m;
    sec = _s;
}

//成员函数的定义
void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
}

//不带参数的构造函数
//如果用户已经定义了构造函数 那么不带参数的构造函数系统就不会创建
Time::Time(void)
{
    hour = 0;
    min = 0;
    sec = 0;
}


int main(void)
{
    //不带参数的构造函数
    Time t;
    //带参数的构造函数 定义对象的时候 初始化
    Time t1(1, 2, 3);
    Time t2(1);
    Time t3(11, 22);

    t.showTime();
    t1.showTime();
    t2.showTime();
    t3.showTime();

    

    return 0;
}
