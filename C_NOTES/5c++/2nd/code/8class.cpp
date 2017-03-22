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

int main(void)
{
    Time t;
    Time *p = NULL;
    //对象的引用 实际尚t1是t的别名
    Time &t1 = t;
    
    //6.1 通过对象名和成员运算符访问对象中的成员
    //只有公有成员才可这样访问 
    t.sec = 60;
    //私有成员 访问非法
    //t.hour = 1;
    cout << "sec: " << t.sec << endl;

    //指针变量指向一个对象
    p = &t;
    p->setTime(1, 1, 1);
    p->showTime();
    t.showTime();
    cout << "==========================" << endl;

    cout << "&t = " << &t << "  &t1 = " << &t1 << endl;
    t1.showTime();



    return 0;
}
