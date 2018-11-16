/*
    realloc
    void* realloc(void *ptr, size_t new_size);
    重新分配给定的内存区域，它必须是之前为 malloc, calloc, realloc 所分配，并没有被释放。

    重新分配按照以下二者之一执行：
    - 可能的话，扩张或收缩 ptr 所指向的已存在内存。内容在新旧大小中的较小者范围内保持不变。若扩张范围，则数组新增部分的内容是未定义的。
    - 分配一个大小为 new_size 字节的新内存块，并复制大小等于新旧大小中较小者的内存区域，然后释放内存块。

    若无足够内存，则不释放旧内存块，并返回空指针。
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int n;
    int *pa = (int*)malloc(10 * sizeof(int));
    if (pa) {
        printf("pa(%p):", pa);
        for (n = 0; n < 10; n++) {
            printf(" %d", pa[n] = n);
        }
        printf("\n");
    }

    int *pb = (int*)realloc(pa, 1000000 * sizeof(int));
    if (pb) {
        printf("pb(%p):", pb);
        for (n = 0; n < 10; n++) {
            printf(" %d", pb[n]);
        }
        printf("\n");
        
        free(pb);
    }
    else {
        free(pa);
    }

    return 0;
}
