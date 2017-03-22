#include <iostream>
#include <list>

using namespace std;


//遍历list
void show(list<int> l)
{
    list<int>::iterator it;

    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}



int main(void)
{

    int a[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};

    list<int> l;
    list<int> l1(&a[0], &a[9]);

    //给容器赋值
    l.assign(&a[0], &a[10]);
    show(l);

    //reverse: 将容器中的元素到转
    l.reverse();
    show(l);

    //push_back: 尾插
    //push_front: 头插
    l.push_front(0);
    l.push_back(110);
    show(l);

    show(l1);
    //merge合并链表
    l.merge(l1);
    show(l);

    //sort 排序
    l.sort();
    show(l);

    //unique 去除重复的元素 前提是链表有序
    l.unique();
    show(l);
    return 0;
}







