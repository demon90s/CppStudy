/*
    关键字 constexpr

    自C++11起， constexpr 可用来让表达式核定于编译期。
*/

constexpr int square(int x)
{
    return x * x;
}

int main()
{
    float a[square(9)];     // OK, 编译期就可以计算得到a有81个元素
    (void)a;

    return 0;
}