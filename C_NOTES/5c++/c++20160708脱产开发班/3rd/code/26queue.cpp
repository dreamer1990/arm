#include <iostream>
//栈相关的头文件
#include <queue>

using namespace std;


#if 0
标准模板库  模板类

    C++ Queues(队列)
    C++队列是一种容器适配器，它给予程序员一种先进先出(FIFO)的数据结构。 
    
    back() 返回最后一个元素 
    empty() 如果队列空则返回真 
    front() 返回第一个元素 
    pop() 删除第一个元素 
    push() 在末尾加入一个元素 
    size() 返回队列中元素的个数 
    
#endif
    

int main(void)
{
    
    int val;
    //queue是类模板
    queue<int> q;
    int i = 0;

    cout << "size: " << q.size() << endl;
    cout << "队列是否为空: " << q.empty() << endl;

    for (i = 0; i < 10; i++)
    {
        q.push(i + 1); 
    }
    cout << "入队列之后 size: " << q.size() << endl;
    cout << "队列是否为空: " << q.empty() << endl;

    cout << "队列队头元素为: " << q.front() << endl;
    cout << "队列 size: " << q.size() << endl;
    cout << "======================" << endl;


    //出队列
    while(!q.empty())
    {
        val = q.front();
        q.pop();
        cout << val << "  ";
    }
    cout << endl;

    return 0;
}
