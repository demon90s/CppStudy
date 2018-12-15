/*
    每次调用时都检查函数 malloc 的返回值是件很烦人的事情。请编写一个名为 my_malloc 的函数，用
    来作为 malloc 函数的“包装器”。当调用函数 my_malloc 并且要求分配n个字节时，它会转到调用
    malloc 函数，判断 malloc 函数确实没有返回空指针，然后返回来自 malloc 的指针。如果 malloc
    返回空指针，那么函数 my_malloc 显示出错信息并且终止程序。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_malloc(size_t count, size_t sz);

int main(int argc, char const *argv[])
{
    char *str = my_malloc(6, sizeof(char));
    strcpy(str, "Hello");

    printf("%s\n", str);

    free(str);

    return 0;
}

void *my_malloc(size_t count, size_t sz)
{
    void *ret = malloc(count * sz);
    if (ret == NULL) {
        printf("No space left!\n");
        exit(EXIT_FAILURE);
    }
    return ret;
}
