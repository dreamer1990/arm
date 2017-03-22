

/*
 *    内部函数：
 *    如果一个函数只能被本文件中其他函数所调用，它称为内部函数。
 *    在定义内部函数时，在函数名和函数类型的前面加 static，即:
 *
 *        static 类型名 函数名(形参表)
 *    内部函数又称静态函数，因为它是用 static 声明的
 *
 *    通常把只能由本文件使用的函数和外部变量放在文件的开头，前面都冠以 static 使之局
 *部化，其他文件不能引用
 *
 *    作用: 
 *    提高了程序的可靠性
 *
 */
 //内部函数
static int add(int x, int y)
{
    return x + y;
}   

/*
 *    外部函数：
 *    如果在定义函数时，在函数首部的最左端加关键字 extern，则此函数是外部函数，可供
 *其他文件调用。
 *    如函数首部可以为
 *        extern int fun (int a, int b)
 *    如果在定义函数时省略 extern，则默认为外部函数
 *
 */
//外部函数  默认extern
int sub(int x, int y)
{
    return x - y;
}

//int mul(int x, int y)与下面等价
extern int mul(int x, int y)
{
    return x * y;
}


