#include <iostream>
#include <queue>
using namespace std;

//队列是先进先出的一个线性结构

int main(void)
{
    int i = 0;
    queue<int> q;

    for (i = 0; i < 10; i++)
    {
        //入队列
        q.push(i + 1);   
    }

    cout << "empty: " << q.empty() << endl;
    cout << "size: " << q.size() << endl;

    //front： 返回队列中第一个元素
    cout << "front: " << q.front() << endl;
    //back： 返回队列中最后一个元素
    cout << "back: " << q.back() << endl;

    //pop删除队列只第一个元素
    while(!q.empty())
    {
        cout << q.front() << " ";
        //删除队列中第一个元素
        q.pop();
    }

    cout << endl;

    cout << "empty: " << q.empty() << endl;
    cout << "size: " << q.size() << endl;
    return 0;
}
