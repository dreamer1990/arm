#include <iostream>

using namespace std;


//普通函数作为友元函数

//前向声明;
class Time;

//日期类
class Date{
public:
    Date();
    Date(int, int, int);
    ~Date();
    void showDate(const Time&);

private:
    int year;
    int mon;
    int day;
};

//时间类
class Time{
public:
    Time();
    Time(int, int, int);
    ~Time();
    void showTime(void);
    //声明类Date是Time的友元类
    friend class Date;
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

//构造函数
Date::Date()
{
    year = 0;
    mon = 0;
    day = 0;
    cout << "Date constructor" << endl;
}

Date::Date(int y, int m, int d):year(y), mon(m), day(d)
{
    cout << "Date y m d constructor" << endl;
}

//友元成员函数 可以访问一个类中的私有成员
void Date::showDate(const Time &t)
{
    cout << year << "-" << mon << "-" << day << "  ";
    cout << t.hour << " : " << t.min << " : " << t.sec << endl;
}

Date::~Date()
{
    cout << "Date destructor" << endl;
}


int main(void)
{
    Time t(17, 24, 35);
    Date d(2016, 9, 20);
    
    d.showDate(t);

    return 0;
}




