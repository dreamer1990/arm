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

//使用迭代器遍历容器
void show_v2(vector<double> v)
{
    //迭代器类型
    vector<double>::iterator it;
    //begin: 返回当前容器起始位置的迭代器
    //end: 返回当前容器的最后一个元素的下一个位置的迭代器
    for (it = v.begin(); it != v.end(); it++)
    {
        //vector中的迭代器可以直接解引用
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
    int a[5] = {1, 2, 3, 4, 5};
    //用5个50来初始化该容器
    vector<int> v(5, 50);
    //构造一个与v相同的容器
    vector<int> v1(v);
    vector<double> v2;

    show_v1(v);
    show_v1(v1);

    //如果两个容器的大小和对应位置的元素一样 那么两个容器相等
    cout << "v == v1: "  << (v == v1) << endl;
    
    //assign是对容器赋值
    v2.assign(5, 100);
    show_v2(v2);

    v.assign(&a[0], &a[5]);
    show_v1(v);
    //capacity：返回vector所能容纳的元素的数量
    cout << "capacity: " << v.capacity() << endl;

    //resize改变元素数量的大小
    v.resize(100);
    cout << "capacity: " << v.capacity() << endl;

    return 0;
}
