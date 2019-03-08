/*
    offsetof 宏
    定义于 stddef.h

    offsetof(s, a)
    计算得到结构s的起点到指定成员a间的字节数。
*/

#include <stddef.h>
#include <stdio.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(int argc, char const *argv[])
{
    printf("offset a: %zu\n", offsetof(struct s, a));  /* 一定是0，因为第一个成员的地址与自身地址相同 */

    printf("offset b: %zu\n", offsetof(struct s, b));

    printf("offset c: %zu\n", offsetof(struct s, c));
    
    return 0;
}
