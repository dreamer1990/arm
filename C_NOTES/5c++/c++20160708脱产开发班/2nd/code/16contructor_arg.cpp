#include <iostream>

using namespace std;


#if 0
 8.3 带参数的构造函数

	可以采用带参数的构造函数，在调用不同对象的构造函数时，从外面将不同的数据传递给构造函数，以实现不同的初始化。构造函数首部的一般格式为
	构造函数名(类型 1 形参1，类型2 形参2，…)

	前面已说明： 用户是不能调用构造函数的，因此无法采用常规的调用函数的方法给出实参。实参是在定义对象时给出的。定义对象的一般格式为 
	类名 对象名(实参1，实参2，…);
#endif


class Time{
public:
    //构造函数
    Time(int, int, int);
    Time(void);
    void setTime(int, int, int);
    void showTime(void);

private:
    int hour;
    int min;
    int sec;
};

//构造函数重载
//构造函数的定义
Time::Time(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
    cout << "constructor....." << endl;
}

Time::Time(void)
{
    cout << "empty contructor" << endl;
}

void Time::setTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}

void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
}

int main(void)
{
    //如果用户定义了构造函数，那么系统默认的构造函数就不存在了. 拷贝构造函数还是存在
    Time t3;
    Time t(1, 2, 3);
    Time t2(11, 22, 33);

    t.showTime();

    t2.showTime();


    t3.setTime(11, 11, 30);
    t3.showTime();

    return 0;
}










