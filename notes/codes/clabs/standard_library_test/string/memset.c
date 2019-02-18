/*
    void *memset(void *s, int c, size_t n);

    将一个字符c的n个副本拷贝到存储区域s。
    函数返回s。
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[5] = "HHHH";
    memset(str, 'O', 2);

    printf("str: %s\n", str);

    return 0;
}
