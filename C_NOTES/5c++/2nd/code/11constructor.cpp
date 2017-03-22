#include <iostream>
using namespace std;


/*
 * 8.4 用参数初始化表对数据成员初始化
 *
 *    C++还提供另一种初始化数据成员的方法——参数初始化表来实现对数据成员的初始化。这种方法不在函数体内对数据成员初始化，而是在函数首部实现。例如定义构造函数可以改用以下形式： 
 *    Box∷Box(int h,int w,int len):height(h)，width(w)，length(len){ }
 *    
 *    这种写法方便、简练，尤其当需要初始化的数据成员较多时更显其优越性。甚至可以直接在类体中(而不是在类外)定义构造函数。
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
    //构造函数
    Time();
    Time(int _h, int _m, int _s);
};

//使用参数初始化表 对数据成员初始化
Time::Time(int h, int s, int m):hour(h), min(m), sec(s){}

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

    t.showTime();
    t1.showTime();
    

    return 0;
}
