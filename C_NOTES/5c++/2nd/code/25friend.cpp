#include <iostream>
using namespace std;

//将普通函数声明为友元函数
class Time
{
public:
    Time();  
    Time(int, int, int);
    friend void showTime(Time &);
private:
    int hour;
    int min;
    int sec;
};

//默认构造函数
Time::Time()
{
    cout << "constructor...." << endl;
}

//友元函数 参数应该要传一个对象进来
void showTime(Time &t)
{
    cout << t.hour << " : " << t.min << " : " << t.sec << endl;

}

//带参数的构造函数
Time::Time(int h, int m, int s)
{
    hour = h;
    min = m;
    sec =s;
}


int main(void)
{

    Time t(1, 2, 3);

    showTime(t);



    return 0;
}
