/*
    请编写下列每个声明指定的x类型的完整描述。

    (a) char (*x[10])(int)
    (b) int (*x(int))[5];
    (c) float *(*x(void))(int)[10];
    (d) void (*x(int, void (*y)(int)))(int);
*/

/*
    (a) 一个名为x的具有10个元素的数组，元素类型是一个函数指针，指向的函数类型的 char (*f)(int)
    (b) x是一个函数，其参数是一个 int ,返回一个指向5个 int 元素的数组的指针
    (c) 有问题，编译提示错误，函数返回了一个数组（C语言中函数没有办法返回数组）
    (d) x是一个函数，参数列表是(int, void (*y)(int)), 其中参数y是一个函数指针，指向的函数有一个 int 型参数，
        无返回类型；x的返回类型也是一个函数指针，指向的函数有一个 int 型参数，无返回类型
*/

char test_a(int i) { return 0; }

float (*test_c(int i))[10] {
    static float a[10];
    return &a;
}

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
    x_a[0] = test_a;

    x_d(0, test_d);

    return 0;
}
