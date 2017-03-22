#include <iostream>
using namespace std;


//声明类类型
class Time{
    //成员函数
    public:
        //设置时间的成员函数
        void setTime(int h, int m, int s);
        //显示时间的成员函数
        void showTime(void);
        //数据成员
    public:
        int hour;
    private:
        int min;
        int sec;
};

//在类中声明成员函数  在类外定义成员函数
void Time::setTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}

void Time::showTime(void)
{
    cout << hour << " : "  << min << " : " << sec << endl;
}

int main(void)
{
    //类类型没有占用空间 只有定义对象之后 对象才占空间
    Time t;
    //声明引用
    Time &t1 = t;

    cout << "&t1:  " << &t1 << "   &t:  " << &t << endl;

    t.setTime(10, 59, 0);
    t.showTime();
    cout << "========================\n";

    t1.setTime(11, 11, 11);
    t1.showTime();
    t.showTime();

    return 0;
}








