#include <iostream>
#include <vector>
using namespace std;

//使用迭代器遍历容器
void show_v1(vector<int> v)
{
    //迭代器类型
    vector<int>::iterator it;
    //begin: 返回当前容器起始位置的迭代器
    //end: 返回当前容器的最后一个元素的下一个位置的迭代器
    for (it = v.begin(); it != v.end(); it++)
    {
        //vector中的迭代器可以直接解引用
        cout << *it << " ";
    }
    cout << endl;
}

//逆向遍历
void show_v2(vector<int> v)
{
    vector<int>::reverse_iterator it;
    for (it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

}

//使用数组的方式 或者at函数遍历容器
void show(vector<int> v)
{
    int i = 0;
    for (i = 0; i < v.size(); i++)
    {
        //v[i]是不安全的方法 不做越界检查
        //cout << v[i] << " ";
        //v.at(i)返回指定位置的元素
        cout << v.at(i) << " ";
    }

    cout << endl;
}

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int>::iterator it;
    //使用区间初始化容器
    vector<int> v(&a[0], &a[10]);

    show_v2(v);
    cout << "=======================" << endl;
    it = v.begin();
    //删除指定位置的元素
    v.erase(it);
    show_v2(v);
    cout << "=======================" << endl;
    
    //inset插入
    v.insert(it, 100); 
    show_v2(v);
    cout << "=======================" << endl;

    v.insert(it, 5, 88);
    show_v2(v);
    cout << "=======================" << endl;

    v.resize(30);
    //迭代器
    it = v.begin();
    v.insert(it, &a[0], &a[6]);
    show_v2(v);
    cout << "=======================" << endl;


   return 0;
}
