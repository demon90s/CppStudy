/*
    编写一个程序，声明书中的结构s，并显示出成员a, b, c的大小和偏移量。（使用 sizeof 来得到大小，
    使用 offsetof 来得到偏移量。）同时使程序显示出整个结构的大小。根据这些信息，判断结构中是否
    包含空洞（无效字节）。如果包含，指出每一个的位置和大小。
*/

/*
    包含了空洞，a与b之间有3个字节的空洞。
*/

#include <stddef.h>
#include <stdio.h>

struct s {
    char a;
    int b[2];
    float c;
} v;

int main(int argc, char const *argv[])
{
    printf("sizeof a: %u, offset a: %u\n", sizeof(v.a), offsetof(struct s, a));  /* 一定是0，因为第一个成员的地址与自身地址相同 */

    printf("sizeof b: %u, offset b: %u\n", sizeof(v.b), offsetof(struct s, b));

    printf("sizeof c: %u, offset c: %u\n", sizeof(v.c), offsetof(struct s, c));

    printf("sizeof struct s: %u\n", sizeof(struct s));
    
    return 0;
}