#include <iostream>

using namespace std;

#if 0

	在使用构造函数和析构函数时，需要特别注意对它们的调用时间和调用顺序。

	在一般情况下，调用析构函数的次序正好与调用构造函数的次序相反：
	最先被调用的构造函数，其对应的(同一对象中的)析构函数最后被调用，
	而最后被调用的构造函数，其对应的析构函数最先被调用。

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
    
    t1.showTime();
    t2.showTime();
    t3.showTime();
    t4.showTime();



    return 0;
}
