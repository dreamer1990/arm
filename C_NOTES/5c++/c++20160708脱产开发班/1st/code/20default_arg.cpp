#include <iostream>

using namespace std;

#define PI 3.1415926



#if 0
    如果有多个形参，可以使每个形参有一个默认值，也可以只对一部分形参指定默认值，另一部分形参不指定默认值。如有一个求圆柱体体积的函数，形参h代表圆柱体的高，r为圆柱体半径。函数原型如下：
    float volume(float h,float r=12.5);          //只对形参r指定默认值12.5
    函数调用可以采用以下形式： 
    volume(45.6);                                //相当于volume(45.6,12.5)
    volume(34.2,10.4)                            //h的值为34.2，r的值为10.4
    实参与形参的结合是从左至右顺序进行的。因此指定默认值的参数必须放在形参表列中的最右端，否则出错。
    
    void f1(float a, int b=0, int c, char d=′a′);     //不正确
    void f2(float a，int c，int b=0, char d=′a′);     //正确
    如果调用上面的f2函数，可以采取下面的形式： 
    f2(3.5, 5, 3, ′x′)                  //形参的值全部从实参得到
    f2(3.5, 5, 3)                      //最后一个形参的值取默认值′a′
    f2(3.5, 5)                         //最后两个形参的值取默认值，b=0,d=′a′

    可以看到，在调用有默认参数的函数时，实参的个数可以与形参的个数不同，实参未给定的，从形参的默认值得到值。利用这一特性，可以使函数的使用更加灵活。
    
#endif

//计算圆柱的体积
double volume(double h, double r = 5)
{
    return h * PI * r * r;
}

//默认的参数必须全部放在形参列表的最右端
//int fun(int x, int y = 22, int z, int w = 33)
int fun(int x, int y, int z = 33, int w = 44)
{
    cout << "fun: " << " x = " << x << " y = " << y << " z = " << z << " w = " << w << endl;
    return x;
}


int main(void)
{
    double h = 3;
    double r = 10;

    //不使用默认值
    cout << "volume(h, r): " << volume(h, r) << endl;

    //使用默认值
    cout << "volume(h):  " << volume(h) << endl;

    //省略的参数一定要有默认的参数 否则会报错
    //fun(1);

    fun(1, 2);
    fun(1, 2, 3);
    fun(1, 2, 3, 4);
    return 0;
}









