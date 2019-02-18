/*
    大端存储、小端存储

    对于一个数，如果是大端存储，那么低位地址存放高位有效字节，如果是小端存储，那么低位存放低位有效字节。

    几乎所有的网络协议都是 big endian
*/

#include <stdio.h>

// 获取系统是 big endian 还是 little endian
union TestEndian {
    short a;
    char b[2];
};
void get_endian()
{
    union TestEndian te;
    te.a = 0x4321;
    if (te.b[0] == 0x43 && te.b[1] == 0x21) {
        printf("this system is big endian\n");
    }
    else if (te.b[0] == 0x21 && te.b[1] == 0x43) {
        printf("this system is little endian\n");
    }
    else {
        printf("unkown\n");
    }
}

int main()
{
    get_endian();

    return 0;
}