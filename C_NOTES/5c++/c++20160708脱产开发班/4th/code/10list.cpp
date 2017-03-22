#include <iostream>
#include <list>
using namespace std;

bool ifmove(int val)
{
    if (val >= 2 && val <= 3)
        return true;
    else
        return false;
}

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
    int a[10] = {1, 2, 1, 3, 4, 5, 6, 1, 7, 8};
    list<int> l;
    list<int> l1;

    //assign: 赋值
    l.assign(&a[0], &a[10]);
    l1.assign(&a[0], &a[6]);
    show(l);

    //unique: 删除list中重复的元素 好像没反应
    //切记：在使用unique之前(不论是list的unique还是泛型的unique)， 都必须先对容器内的元素进行排序， 因为unique()是比较相邻的元素. 去掉相邻元素中重复的...
    l.sort();
    l.unique();
    show(l);

    //pop_back: 删除最后一个元素
    l.pop_back();
    //pop_front: 删除第一个元素
    l.pop_front();
    show(l);

    //返回list能容纳的最大元素的数量
    cout << "list max size: " << l.max_size() << endl;

    //两个链表在合并之前必须是有序
    l.sort(mycmp);
    l1.sort(mycmp);
    //l.merge(l1); 
    l.merge(l1, mycmp);
    show(l);
    
    //删除第一个元素
    l.erase(l.begin());
    show(l);
    //remove(val): 删除所有的val元素
    l.remove(1);
    show(l);

    //根据谓词删除指定的元素
    l.remove_if(ifmove);
    show(l);

    l.insert(l.end(), 5, 88);
    show(l);

    //删除所有的元素
    l.clear();
    show(l);
    return 0;
}
