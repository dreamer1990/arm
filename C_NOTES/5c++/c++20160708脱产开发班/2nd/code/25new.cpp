#include <iostream>

using namespace std;

class Time
{
public:
    //带默认参数值的构造函数
    //Time(int h = 0, int m = 0, int s = 0);
    Time(int  = 0, int  = 0, int  = 0);
    //析构函数
    ~Time(void);
    void showTime(void);
    Time *getPtr(void);


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
    cout << this->hour << " : " << this->min << " : " << this->sec << endl;
}

//析构函数的定义
Time::~Time(void)
{

    cout << this->hour << " : " << this->min << " : " << this->sec << "   ";
    cout << "destructor" << endl;
}

Time* Time::getPtr(void)
{
    return this;
}

int main(void)
{
    Time *p = NULL;
    Time *p1 = NULL;

    //对象的动态建立
    p = new Time(1, 2, 3);
    p1 = new Time;

    p->showTime();

    p1->showTime();


    //销毁对象 调用析构函数
    delete p;
    delete p1;

    return 0;
}
