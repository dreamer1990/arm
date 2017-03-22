#include <iostream>
using namespace std;


/*
 *    为了使结构体类型也具有封装的特征，C++不是简单地继承C的结构体，而是使它也具有类的特点，以便于用于面向对象程序设计。
 *    用struct声明的结构体类型实际上也就是类。
 *
 *    用struct声明的类，如果对其成员不作private或public的声明，系统将其默认为public。如果想分别指定私有成员和公用成员，则应用private或public作显式声明。
 *    而用class定义的类，如果不作private或public声明，系统将其成员默认为private，在需要时也可以自己用显式声明改变。
 *
 *    如果希望成员是公用的，使用struct比较方便，如果希望部分成员是私有的，宜用class。建议尽量使用class来建立类，写出完全体现C++风格的程序。
 *
 */

//使用struct声明类类型
struct Time{
public:
    //设置时间的成员函数
    void setTime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }
    //显示时间的成员函数
    void showTime(void)
    {
        cout << hour << " : "  << min << " : " << sec << endl;
    }

private:
    int hour;
    int min;
    int sec;
};

int main(void)
{
    //类类型没有占用空间 只有定义对象之后 对象才占空间
    Time t;
    t.setTime(10, 59, 0);
    t.showTime();


    return 0;
}








