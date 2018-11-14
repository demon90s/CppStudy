/*
    假设s具有下列结构：
    struct {
        float a;
        union {
            char b[4];
            float c;
            int d;
        } e;
    };

    如果 char 型值占有1个字节， int 型值占有2个字节，而 float 型值占有4个字节，那么编译器将为s分配多大的内存空间？
    （假设编译器没有在成员之间留“空洞”。）
*/

/*
    8个字节。
*/

#include <stdio.h>

#pragma pack(push, 1)   /* 1字节对齐，保证不留空洞 */

struct T {
    float a;
    union {
        char b[4];
        float c;
        int d;
    } e;
};

#pragma pack(pop)

int main(int argc, char const *argv[])
{
    printf("%u\n", sizeof(struct T));
    return 0;
}
