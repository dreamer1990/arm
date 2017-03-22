#include <iostream>
using namespace std;
/*
 *
 *    访问对象中成员的一般形式为
 *    对象名.成员名
 *
 */

//类的声明
class Time{
//私有
private:
    int hour;
    int min;
//公有
public:
    int sec;

public:
    void setTime(int _h, int _m, int _s);
    void showTime(void);
    //构造函数
    Time();
    Time(int _h, int _m, int _s);
};

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
Time::Time()
{
    hour = 0;
    min = 0;
    sec = 0;
}

//带有参数的构造函数
Time::Time(int _h, int _m, int _s)
{
    hour = _h;
    min = _m;
    sec = _s;
}


int main(void)
{
    //不带参数的构造函数
    Time t;
    //带参数的构造函数
    Time t1(1, 2, 3);

    t.showTime();
    t1.showTime();
    

    return 0;
}
