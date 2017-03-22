#include <iostream>

using namespace std;

//类的声明
class Time{
public:
    Time();
    Time(int, int, int);
    ~Time();
    void showTime(void);
    void setMsec(int a);
private:
    int hour;
    int min;
    int sec;
    static int msec;
    //静态数据成员不占用对象的空间 它属于类 不属于具体的对象 
};

//默认构造函数
Time::Time()
{
    hour = 0;
    min = 0;
    sec = 0;
    cout << "empty constructor" << endl;
}

Time::~Time()
{
    cout << "destructor" << endl;
}

//使用初始化表的构造函数
Time::Time(int h, int m, int s):hour(h), min(m), sec(s){}

//自定义成员函数
void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
    //可以访问静态数据成员
    cout << "msec: " << msec << endl;
}

void Time::setMsec(int a)
{
    //静态数据成员 可以通过非静态成员函数访问  并且修改
    msec = a;
}

//静态成员在类外进行初始化
int Time::msec = 33;

int main(void)
{

    //私有的成员不能在类外访问
    //cout << "msec:  " << Time::msec << endl;

    Time t(10, 10, 10);
    t.showTime();
    t.setMsec(100);

    t.showTime();

    return 0;
}




