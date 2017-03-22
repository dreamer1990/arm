#include <iostream>

using namespace std;



#if 0
    
    12.2 内联函数
    调用函数时需要一定的时间和空间的开销
    
    C++提供一种提高效率的方法，即在编译时将所调用函数的代码直接嵌入到主调函数中，而不是将流程转出去。这种嵌入到主调函数中的函数称为内置函数(inline function)，又称内嵌函数。在有些书中把它译成内联函数。
    指定内置函数的方法很简单，只需在函数首行的左端加一个关键字inline即可。
    
    注意： 可以在声明函数和定义函数时同时写inline，也可以只在其中一处声明inline，效果相同，都能按内置函数处理。
    使用内置函数可以节省运行时间，但却增加了目标程序的长度。因此一般只将规模很小(一般为5个语句以下)而使用频繁的函数(如定时采集数据的函数)声明为内置函数。
    
    内置函数中不能包括复杂的控制语句，如循环语句和switch语句。
    应当说明： 对函数作inline声明，只是程序设计者对编译系统提出的一个建议，也就是说它是建议性的，而不是指令性的。并非一经指定为inline，编译系统就必须这样做。编译系统会根据具体情况决定是否这样做。
    归纳起来，只有那些规模较小而又被频繁调用的简单函数，才适合于声明为inline函数。
    
#endif

//inline是关键字
inline int add(int a, int b)
{
    return a + b;
}

inline int sub(int a, int b);

int mul(int a, int b);

int main(void)
{
    int a = 3;
    int b = 4;

    cout << "a + b = " << add(a, b) << endl;
    cout << "a - b = " << sub(a, b) << endl;
    cout << "a * b = " << mul(a, b) << endl;

    return 0;
}

int sub(int a, int b)
{
    return a - b;
}

inline int mul(int a, int b)
{
    return a * b;
}
