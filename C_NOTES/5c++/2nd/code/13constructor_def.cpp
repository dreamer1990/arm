#include <iostream>
using namespace std;



/*
 *
 *    说明： 
 *    (1) 应该在声明构造函数时指定默认值，而不能只在定义构造函数时指定默认值。
 *    (2) 程序在声明构造函数时，形参名可以省略。
 *    (3) 如果构造函数的全部参数都指定了默认值，则在定义对象时可以给一个或几个实参，也可以不给出实参。
 *    (4) 在一个类中定义了全部是默认参数的构造函数后，不能再定义重载构造函数。
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
    //带有默认参数的构造函数
    Time(int h = 10, int m = 10, int s = 10):hour(h), min(m), sec(s){cout << "constructor called." << endl;}
};

#if 0
//构造函数定义
Time::Time(int h, int m, int s)
{
    hour = h; min = m; sec = s;
}
#endif


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
    //不带参数的构造函数
    Time t;
    //带参数的构造函数 定义对象的时候 初始化
    Time t1(1);
    Time t2(11, 22);
    Time t3(1, 2, 3);

    t.showTime();
    t1.showTime();
    t2.showTime();
    t3.showTime();
    

    return 0;
}
