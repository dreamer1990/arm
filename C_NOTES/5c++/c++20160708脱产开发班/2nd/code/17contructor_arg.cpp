#include <iostream>

using namespace std;


#if 0

	C++还提供另一种初始化数据成员的方法——参数初始化表来实现对数据成员的初始化。
	这种方法不在函数体内对数据成员初始化，而是在函数首部实现。
	例如定义构造函数可以改用以下形式： 
	Box∷Box(int h,int w,int len):height(h)，width(w)，length(len){ }
	
	这种写法方便、简练，尤其当需要初始化的数据成员较多时更显其优越性。
	甚至可以直接在类体中(而不是在类外)定义构造函数。

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

//参数初始化表来实现对数据成员进行初始化
//构造函数的定义
Time::Time(int h, int m, int s):hour(h), min(m), sec(s)
{
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










