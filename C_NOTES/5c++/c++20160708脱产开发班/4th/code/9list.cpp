#include <iostream>
#include <list>
using namespace std;

//回调函数
int mycmp(int x, int y)
{
    return x > y;
}

void show(list<int> l)
{
    //迭代器
    list<int>::iterator it;

    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//逆向遍历
void show_reverse(list<int> l)
{
    //逆向迭代器
    list<int>::reverse_iterator it; 
    for (it = l.rbegin(); it != l.rend(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}


int main(void)
{
    int i = 0;
    list<int> l1;
    list<int> l2;

    for (i = 0; i < 10; i++)
    {
        //在list的末尾添加一个元素
        l1.push_back(i + 1); 
        //在list的头部添加一个元素
        l2.push_front(i + 1);
    }
    show(l1);

    //back: 返回最后一个元素
    cout << "最后一个元素为:  " << l1.back() << endl;
    cout << "list是否为空； " << l1.empty() << endl;

    //front: 返回第一个元素
    cout << "list第一个元素为: " << l1.front() << endl;
    cout << "list中的元素的个数为:  " << l1.size() << endl;

    cout << "======================" << endl;
    show(l2);
    show_reverse(l2);

    //resize: 改变list的大小 被加入的多余的元素赋值为val
    l2.resize(15, 88);
    show(l2);
    
    //reverse: 将list中所有的元素倒转
    l2.reverse();
    show(l2);
    
    //sort: 默认是升序
    l2.sort();
    show(l2);

    l2.sort(mycmp);
    show(l2);
    

    //swap: 交换两个list
    l2.swap(l1);
    show(l1);
    show(l2);

    cout << "==================" << endl;
    //splice: 合并两个链表
    l2.splice(l2.end(), l1);
    show(l2);


    return 0;
}
