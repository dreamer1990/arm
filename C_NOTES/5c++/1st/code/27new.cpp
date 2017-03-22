#include <iostream>

using namespace std;


int main(void)
{
    int i = 0;
    int *p = NULL;

    //给数组分配空间的时候 不能初始化
    //p = new int[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9. 10};
    //分配10 * sizeof(int)个字节的空间
    p = new int[10];
    if (NULL == p)
    {
        cout << "new space failed..." << endl;
        goto err0;
    }

    //赋值
    for (i = 0; i < 10; i++)
        *(p + i) = i + 1;
    //输出
    for (i = 0; i < 10; i++)
        cout << p[i] << "  " ;
    //换行
    cout << endl;

    delete [] p;

    return 0;
err0:
    return -1;
}
