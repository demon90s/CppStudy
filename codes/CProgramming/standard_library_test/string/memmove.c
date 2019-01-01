/*
    void* memmove(void *des, const void *src, size_t num);
    从 src 中拷贝 num 个字节到 des 。
    返回 des 。
    为了避免 overflow ，需要保证 des 和 src 的空间都至少 num 个字节大小。
    des 和 src 的空间可以重叠。
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[] = "memmove can be very useful.....";
    memmove(str + 20, str + 15, 11);
    puts(str);

    return 0;
}
