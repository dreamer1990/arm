#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int i = 0;
    //创建一个保存int类型元素的栈
    stack<int> s;

    for (i = 0; i < 10; i++)
    {
        //压栈 
        s.push(i + 1);
    }

    //empty 判断栈是否为空
    cout << "The stack is empty:  " << s.empty() << endl;
    //size 返回栈中元素的个数
    cout << "the number of element in the stack is :  " << s.size() << endl;

    //top: 返回栈顶元素 
    cout << "top: " << s.top() << endl;
    //pop: 移除栈顶的元素

    while(!s.empty())
    {
        cout << s.top() << " "; 
        s.pop(); 
    }
    cout << endl;

    return 0;
}
