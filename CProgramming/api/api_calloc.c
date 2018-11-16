/*
 * calloc
 * 为 num 个对象的数组分配内存，并初始化所有分配存储中的字节为0。
 * 
 * 成功时，返回指向新分配的内存的指针。为避免内存泄漏，必须用 free 或 realloc 解分配返回的指针。
 * 失败时，返回空指针。
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i = 0;

    int *arr = (int*)calloc(4, sizeof(int));
    if (arr) {
        for (i = 0; i < 4; i++)
            printf("%d ", arr[i]);
    }

    free(arr);
    
    return 0;
}
