#include <iostream>

using namespace std;


//普通函数作为友元函数

//类的声明
class Time{
public:
    Time();
    Time(int, int, int);
    ~Time();
    void showTime(void);
    friend void show(const Time &);
private:
    int hour;
    int min;
    int sec;
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
Time::Time(int h, int m, int s):hour(h), min(m), sec(s){
    cout << "constructor" << endl;
}

//自定义成员函数
void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
}

//普通友元函数的定义
void show(const Time &t)
{
    cout << "友元: ";
    //可以访问私有数据成员
    cout << t.hour << " : " << t.min << " : " << t.sec << endl;
}

int main(void)
{
    Time t(12, 12, 12);
    t.showTime();

    show(t);

    return 0;
}




