#include <iostream>

using namespace std;

#if 0
	说明： 
	(1) 应该在声明构造函数时指定默认值，而不能只在定义构造函数时指定默认值。
	(2) 程序第5行在声明构造函数时，形参名可以省略。
	(3) 如果构造函数的全部参数都指定了默认值，则在定义对象时可以给一个或几个实参，
	也可以不给出实参。
	(4) 在一个类中定义了全部是默认参数的构造函数后，不能再定义重载构造函数。
#endif


class Time
{
public:
    //带默认参数值的构造函数
    //Time(int h = 0, int m = 0, int s = 0);
    Time(int  = 0, int  = 0, int  = 0);
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
