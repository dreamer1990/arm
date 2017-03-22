
int a = 100;

//防止其它文件中有同名的全局变量b
static int b = 200;


int add(int x, int y)
{
    return x + y;
}

/*
 *  3). 将外部变量的作用域限制在本文件中
 *  有时在程序设计中希望某些外部变量只限于被本文件引用。这时可以在定义外部变量时加一个 static 声明。
 *
 */
//防止其他文件中调用该函数
static int sub(int x, int y)
{
    return x - y;
}
