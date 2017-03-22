#include <iostream>

using namespace std;

//类的声明
class Time{
public:
    Time();
    Time(int, int, int);
    ~Time();
    void showTime(void);
public:
    static int msec;
private:
    int hour;
    int min;
    int sec;
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
}

//静态成员在类外进行初始化
int Time::msec = 33;

int main(void)
{

    Time t(1, 2, 3);
    cout << "sizeof(t): " << sizeof(t) << endl;
 
    cout << "msec: " << Time::msec << endl;
    //通过类名引用静态数据成员
    Time::msec = 100;
    cout << "msec: " << Time::msec << endl;
    //静态数据成员可以通过对象来引用 但是静态数据成员不属于某一个对象
    t.msec = 88;
    cout << "msec: " << t.msec << endl;

    return 0;
}
