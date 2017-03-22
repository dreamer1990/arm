#include <iostream>
#include <list>
using namespace std;


//通过迭代器访问容器
void show(list<int> v)
{
    //定义迭代器类型的变量
    list<int>::iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

//通过迭代器访问容器
void show(list<int> v, int i, int j)
{
    //定义迭代器类型的变量
    list<int>::reverse_iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

//通过迭代器访问容器
void const_show(list<int> v, int i)
{
    //定义迭代器类型的变量
    list<int>::const_iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " "; 
        //常量迭代器  不能改变指向的数据的值
        //*it = 88;
    }
    cout << endl;
}

int main(void)
{

    int i = 0;

    int a[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};

    //list是顺序容器 与以前的动态数组类似
    //调用构造函数  5个88来初始化容器
    list<int> v(5, 88);
    //以已经存在容器来初始化另外一个容器
    list<int> v1(v);

    list<int> v2(&a[0], &a[10]);

    show(v);
    show(v1);
    show(v2);

    //front 返回第一个元素
    cout << "front:  " << v2.front() << endl;
    //back 返回最后一个元素
    cout << "back: " << v2.back() << endl;
    cout << "size: " << v2.size() << endl;

    //max_size: 容器list能够容纳最大元素的数量
    cout << "max_size: " << v2.max_size() << endl;
    //resize: 改变容器元素的个数
    v2.resize(8);
    show(v2);

    //swap: 交换两个容器
    v2.swap(v1);
    cout << "v2: ";
    show(v2);
    cout << "v1: ";
    show(v1);

    //在容器的最后面添加一个元素
    v2.push_back(0);
    show(v2);

    //逆向遍历
    while(!v2.empty())
    {
        //返回容器最后一个元素
        cout << v2.back() << " ";
        //移除容器中最后一个元素
        v2.pop_back();
    }
    cout << endl;

    cout << "empty: " << v2.empty() << endl;
    cout << "size: " << v2.size() << endl;

    return 0;
}





