/*
    void* bsearch(const void* key, const void *base, 
                size_t nmemb, size_t size, 
                int (*compare)(const void* p1, const void *p2));
    二分查询有序数组 base 中的 key 元素，返回其指针，如果找不到，返回 NULL 。

    数组 base 的每个元素的大小为 size ，元素的个数为 nmemb 。

    比较函数 compare 和 qsort 的差不多。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Foo {
    char *name;
    int power;
};

int compare_foo(const void* p1, const void* p2)
{
    return strcmp(((struct Foo*)p1)->name, ((struct Foo*)p2)->name);
}

int main(int argc, char const *argv[])
{
    struct Foo foo_list[5] = {
        {"Foo", 100},
        {"Goo", 87},
        {"Drre", 76},
        {"Bar", 99},
        {"Wens", 29}
    };
    int i;
    char name[32];
    struct Foo *p;
    struct Foo tmp;

    qsort(foo_list, 5, sizeof(struct Foo), compare_foo);
    /*for (i = 0; i < 5; i++) {
        printf(" {%s %d}", foo_list[i].name, foo_list[i].power);
    }
    printf("\n");*/

    printf("Enter name to search: ");
    scanf("%s", name);

    tmp.name = name;

    p = (struct Foo*)bsearch(&tmp, foo_list, 5, sizeof(struct Foo), compare_foo);
    if (p) {
        printf("Found, {%s %d}\n", p->name, p->power);
    }
    else {
        printf("Not found\n");
    }

    return 0;
}