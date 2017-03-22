#include <iostream>
//栈相关的头文件
#include <stack>

using namespace std;


#if 0
标准模板库  模板类

    C++ Stacks（堆栈）
    C++ Stack（堆栈） 是一个容器类的改编，为程序员提供了堆栈的全部功能，——也就是说实现了一个先进后出（FILO）的数据结构。
    
    操作 比较和分配堆栈 
    empty() 堆栈为空则返回真 
    pop() 移除栈顶元素 
    push() 在栈顶增加元素 
    size() 返回栈中元素数目 
    top() 返回栈顶元素 
#endif
    

int main(void)
{
    
    int val;
    //stack是类模板
    stack<int> s;
    int i = 0;

    cout << "size: " << s.size() << endl;
    cout << "栈是否为空: " << s.empty() << endl;

    for (i = 0; i < 10; i++)
    {
        s.push(i + 1); 
    }
    cout << "压栈之后 size: " << s.size() << endl;
    cout << "栈是否为空: " << s.empty() << endl;

    cout << "栈顶元素为: " << s.top() << endl;
    cout << "压栈之后 size: " << s.size() << endl;
    cout << "======================" << endl;

    //弹栈
    while(!s.empty())
    {
        val = s.top();
        s.pop();
        cout << val << "  ";
    }
    cout << endl;
    return 0;
}
