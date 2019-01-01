/*
    在下列声明中，结构x和结构y都拥有名为x和y的成员：

    struct { int x, y; } x;
    struct { int x, y; } y;

    基于独立的基础而言，这些声明是否合法呢？两个声明是否可以同时出现在程序中呢？请证明你的
    想法是正确的。

    answer: 可以。编译通过即证明。
*/

struct { int x, y; } x;
struct { int x, y; } y;

int main(int argc, char const *argv[])
{
    return 0;
}
