#include "time.h"

//成员函数的实现


//成员函数的定义
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
