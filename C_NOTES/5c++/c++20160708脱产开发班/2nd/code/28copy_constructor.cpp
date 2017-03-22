#include <iostream>

using namespace std;

class Time
{
public:
    //带默认参数值的构造函数
    //Time(int h = 0, int m = 0, int s = 0);
    Time(int  = 0, int  = 0, int  = 0);
    //自定义拷贝构造函数
    Time(const Time&);
    //析构函数
    ~Time(void);
    void showTime(void);
    //返回对象的函数
    Time getObj(void);


private:
    int hour;
    int min;
    int sec;
};

//构造函数的定义
//Time::Time(int h = 0, int m = 0, int s = 0)  //带有默认参数的 只能在声明的时候指定 不能在类外定义函数时指定
Time::Time(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
    cout << "constructor" << endl;
}

Time::Time(const Time &t)
{
    hour = t.hour;
    min = t.min;
    sec = t.sec;
    cout << "copy constructor" << endl;
}

Time Time::getObj(void)
{
    return *this;
}

//成员函数的定义
void Time::showTime(void)
{
    cout << this->hour << " : " << this->min << " : " << this->sec << endl;
}

//析构函数的定义
Time::~Time(void)
{

    cout << this->hour << " : " << this->min << " : " << this->sec << "   ";
    cout << "destructor" << endl;
}

int main(void)
{

    //拷贝构造函数
    
    Time t(11, 11, 11);
    //如果用户定义了拷贝构造函数 那么系统就不会提供默认的拷贝构造函数
    //自动调用系统默认的拷贝构造函数
    Time t1(t);

    Time t3;

    t.showTime();
    t1.showTime();
    
    cout << "====================" << endl;
    //调用拷贝构造函数
    t3 = t1.getObj();
    t3.showTime();

    return 0;
}
