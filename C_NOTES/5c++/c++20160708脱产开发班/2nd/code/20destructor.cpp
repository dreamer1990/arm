#include <iostream>

using namespace std;

#if 0

	析构函数的作用并不是删除对象，而是在撤销对象占用的内存之前完成一些清理工作，
	使这部分内存可以被程序分配给新对象使用。程序设计者事先设计好析构函数，
	以完成所需的功能，只要对象的生命期结束，程序就自动执行析构函数来完成这些工作。

	析构函数不返回任何值，没有函数类型，也没有函数参数。因此它不能被重载。
	一个类可以有多个构造函数，但只能有一个析构函数。

	实际上，析构函数的作用并不仅限于释放资源方面，它还可以被用来执行“用户希望在
	最后一次使用对象之后所执行的任何操作”，例如输出有关的信息。这里说的用户是指类的设计者，
	因为，析构函数是在声明类的时候定义的。也就是说，析构函数可以完成类的设计者所指定的任
	何操作。

	一般情况下，类的设计者应当在声明类的同时定义析构函数，以指定如何完成“清理”的工作。
	如果用户没有定义析构函数，C++编译系统会自动生成一个析构函数，但它只是徒有析构函数的
	名称和形式，实际上什么操作都不进行。想让析构函数完成任何工作，都必须在定义的析构函数
	中指定。

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
