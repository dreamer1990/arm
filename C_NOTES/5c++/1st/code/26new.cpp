#include <iostream>
#include <string.h>

using namespace std;

//new和delete是运算符  

int main(void)
{
    int *p = NULL;
    int *p1 = NULL;
    float *pf = NULL;

    //分配sizeof(int)字节的空间 默认初始化为0
    p = new int;
    //如果没有初始化 则会有bug
    memset(p, 0, sizeof(int));
    //分配4个字节的空间 并且初始化为100
    p1 = new int(100);

    pf = new float(3.14);

    cout << "*p = " << *p << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*pf = " << *pf << endl;


    //释放空间
    delete p;
    p = NULL;
    delete p1;
    p1 = NULL;
    delete pf;
    pf = NULL;


    return 0;
}
