#include <iostream>
using namespace std;

#if 0
	在C++中，声明了类类型后，定义对象有两种形式。
	1） class 类名 对象名 
	如 class Student  stud1,stud2;
	把class和Student合起来作为一个类名，用来定义对象。

	2） 类名 对象名 
	如 Student  stud1，stud2;
	直接用类名定义对象。这两种方法是等效的。第1种方法是从C语言继承下来的，第2种方法是C++的特色，显然第2种方法更为简捷方便。
#endif


//class是关键字
//Time是类名
class Time{
//公有成员
public:
    //设置时间
    void setTime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }

    //输出时间
    void display(void)
    {
        cout << hour << " : " << min << " : " << sec << endl;
    }

//私有成员
private:
    int hour;
    int min;
    int sec;
};

int main(void)
{
    class Time t1;
    Time t2;
    t1.setTime(10, 29, 30);
    t1.display();

    t2.setTime(11, 29, 30);
    t2.display();
    //不能通过对象名访问私有成员
    //t1.hour = 33;

    return 0;
}
