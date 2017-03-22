#include <iostream>

using namespace std;

#if 0

	定义指向公用成员函数的指针变量的一般形式为 
	数据类型名 (类名::*指针变量名)(参数表列)；


	使指针变量指向一个公用成员函数的一般形式为 
	指针变量名=&类名∷成员函数名;

#endif


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
    Time t1;
    Time t2(1);
    Time t3(1, 2);
    Time t4(1, 2, 3);
    //定义指向成员函数的指针
    void (Time::*p)(void) = NULL;

    //&不能少  否则报错
    p = &Time::showTime;
    
    t1.showTime();
    t2.showTime();
    t3.showTime();
    t4.showTime();

    cout << "=======================" << endl;
    //括号不能省略
    (t1.*p)();
    (t4.*p)();

    return 0;
}
