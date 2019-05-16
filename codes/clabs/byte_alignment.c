/*
    字节对齐

    指的是代码编译后内存的布局方式。

    可以提高内存访问的效率。

    在 Ubuntu 18.04 下测试，总结出这样的对齐规律：
    将结构体中最大内置类型的成员的长度与当前的字节对齐值（比如是4）对比，如果谁小，那么就按谁来对齐。
*/

#include <stdio.h>

// test on 64 bit system

struct A {
    char c;
    char b[2];
}; // 1 byte alignment, total 3 bytes

struct B {
    char c;
    short a;
}; // 2 byte alignment, total 4 bytes

struct C {
    char c;
    short a;
    int i;
}; // 4 byte alignment, total 8 bytes

struct D {
    char c;
    short a;
    double d;
    int i;
}; // 8 byte alignment, total 24 bytes

// 强制4字节对齐
#pragma pack(push)
#pragma pack(4)
struct E {
    char c;
    short a;
    double d;
    int i;
}; // 4 byte alignment, total 16 bytes
#pragma pack(pop)

int main()
{
    printf("sizeof struct A: %zu\n", sizeof(struct A));

    printf("sizeof struct B: %zu\n", sizeof(struct B));

    printf("sizeof struct C: %zu\n", sizeof(struct C));

    printf("sizeof struct D: %zu\n", sizeof(struct D));

    printf("sizeof struct E: %zu\n", sizeof(struct E));

    return 0;
}