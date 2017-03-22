#include <iostream>
using namespace std;

//前向声明
class Date;

//将普通函数声明为友元函数
class Time
{
public:
    Time();  
    Time(int, int, int);
    void show(Date &);
private:
    int hour;
    int min;
    int sec;
};

class Date
{
public:
    Date();
    Date(int, int, int);
    //成员函数作为友元函数
    friend void Time::show(Date&);
private:
    int year;
    int mon;
    int day;
};

//默认构造函数
Time::Time()
{
    cout << "constructor...." << endl;
}

//带参数的构造函数
Time::Time(int h, int m, int s)
{
    hour = h;
    min = m;
    sec =s;
}

void Time::show(Date &d)
{
    cout << d.year << "-" << d.mon << "-" << d.day << "  ";
    cout << hour << " : " << min << " : " << sec << endl;
}

Date::Date()
{
    cout << "constructor.." << endl;
}

Date::Date(int y, int m, int d):year(y), mon(m), day(d){}


int main(void)
{

    Time t(11, 15, 30);
    Date d(2016, 9, 11);

    t.show(d);



    return 0;
}
