/*
    请利用一系列的类型定义来简化练习6中的每个声明。
*/

/*
    for a
*/
typedef char (*FuncA)(int);
typedef FuncA ArrA[10];

/*
    for b
*/
typedef int Arr5Int[5];
typedef Arr5Int* (*FuncB)(int);

/*
    for d
*/
typedef void (*FuncDRet)(int);
typedef FuncDRet (*FuncD)(int, FuncDRet);

char test_a(int i) { return 0; }

void test_d(int i) {}

char (*x_a[10])(int);

int (*x_b(int i))[5] {
    static int a[5];
    return &a;
}

/* float *(*x_c(void))(int)[10]; */

void (*x_d(int i, void (*y)(int)))(int)
{
    return test_d;
}

int main(int argc, char const *argv[])
{
    ArrA arr_a;
    arr_a[0] = test_a;
    arr_a[0](0);

    FuncB func_b;
    func_b = x_b;
    func_b(0);

    FuncD func_d;
    func_d = x_d;
    func_d(0, test_d);

    return 0;
}
