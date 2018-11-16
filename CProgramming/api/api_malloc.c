/*
 * malloc
 * 分配 size 字节的未初始化内存。
 * void* malloc(size)
 * 
 * 成功时，返回指向新分配内存的指针。为避免内存泄漏，必须用 free 或 realloc 解分配返回的指针。
 * 失败时，返回空指针。
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *p = (char*)malloc(sizeof(char) * 5 + 1);
    if (p) {
        strcpy(p, "hello");
        printf("%s\n", p);
    }

    free(p);

    return 0;
}
