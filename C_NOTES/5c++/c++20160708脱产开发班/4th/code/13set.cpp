#include <iostream>
#include <set>
using namespace std;

void show(set<int> s)
{
    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

//关联容器
int main(void)
{
    //该容器默认有序
    //不存在重复的元素
    set<int> s;
    int i = 0;
    
    s.insert(s.end(), 1);
    s.insert(s.end(), 2);
    s.insert(s.end(), 4);
    s.insert(s.end(), 4);
    s.insert(s.end(), 3);
    s.insert(s.end(), 5);
    show(s);     
    //size返回集合中元素的数
    cout << "集合中元素的数目； " << s.size() << endl;
    //count返回某个值元素的数目
    cout << "3 的数目为: " << s.count(3) << endl;

    //find: 查找
    cout << "找到 " << *s.find(3) << endl;

    cout << "max size: " << s.max_size() << endl;
    return 0;
}







