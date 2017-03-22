#include <iostream>

using namespace std;

class Time{
public:
    int hour;
    int min;
    int sec;

    void showTime(void);
//private:
//   int msec;
};

void Time::showTime(void)
{
    cout << hour << " : " << min << " : " << sec << endl;
}


/*
 *    这种情况和结构体变量的初始化是差不多的，在一个花括号内顺序列出各公用数据成员的值，两个值之间用逗号分隔。但是，如果数据成员是私有的，或者类中有private或protected的成员，就不能用这种方法初始化。
 *
 */
int main(void)
{

    //不建议使用该初始化方法
    //对于公有成员  可以类似于结构体那样 初始化 
    Time t = {11, 11, 11};

    t.showTime();

    return 0;
}
