#include <iostream>
#include <set>
using namespace std;


//multiset容器的遍历
void show(multiset<int> s)
{
    multiset<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

//multiset容器的遍历
void show(multiset<int> s, int i)
{
    //逆向迭代器
    multiset<int>::reverse_iterator it;

    for (it = s.rbegin(); it != s.rend(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 5, 6, 7};
    //允许有重复的元素
    multiset<int> s(&a[0], &a[10]);    

    show(s);
    show(s, 1);

    //插入  按顺序
    s.insert(0);
    s.insert(s.begin(), 88);
    show(s);

    return 0;
}










