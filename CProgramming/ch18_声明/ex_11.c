/*
    下列哪些类型的变量不能进行初始化？

    (a) 数组变量
    (b) 枚举变量
    (c) 结构变量
    (d) 联合变量
    (e) 不是上述类型的变量
*/

/*
    e
*/

enum B { FOO, GOO };

struct S { int v; };

union U { int i; char v[4]; };

int main(int argc, char const *argv[])
{
    int arr[] = {0};
    (void)arr;

    enum B b = FOO;
    (void)b;

    struct S s = {0};
    (void)s;

    union U u = {0};
    (void)u;

    return 0;
}
