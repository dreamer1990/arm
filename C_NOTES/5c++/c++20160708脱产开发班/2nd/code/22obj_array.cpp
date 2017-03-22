#include <iostream>

using namespace std;

//对象数组

class Time
{
public:
    //带默认参数值的构造函数
    //Time(int h = 0, int m = 0, int s = 0);
    Time(int  = 0, int  = 0, int  = 0);
    //析构函数
    ~Time(void);
    void showTime(void);

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

//成员函数的定义
void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
}

//析构函数的定义
Time::~Time(void)
{

    cout << hour << " : " << min << " : " << sec << "   ";
    cout << "destructor" << endl;
}

int main(void)
{
    int i = 0;

    Time t[5] = {
        Time(1, 2, 3),
        Time(1, 2, 4),
        Time(1, 2, 5),
        Time(1, 2, 6),
        Time(1, 2, 7),
    };

    for (i = 0; i < 5; i++)
    {
        t[i].showTime();
    }

    return 0;
}
