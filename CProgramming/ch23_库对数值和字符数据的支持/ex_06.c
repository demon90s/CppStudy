/*
    对于下面列举的每种情况，指出使用 memcpy, memmove, strcpy 和 strncpy 中哪一个函数最好。
    假定所列举的行为都是由一个函数调用完成的。

    (a) 将数组中的每个元素都下移一个位置，以便将第0个位置空出给新的元素。
    (b) 通过将后面的所有字符都前移一个字节来删除以空字符结尾的字符串中的第一个字符。
    (c) 将一个字符串复制到一个字符数组中，这个字符数组的大小可能不够存放整个字符串。如果数组
        太小，就将字符串截断，而且在字符数组的末尾不需要空字符作为结尾。
    (d) 将一个数组变量的内容复制到另一个数组变量中。
*/

/*
    a b: memmove
    c: strncpy
    d: strcpy
*/

#include <string.h>
#include <stdio.h>

void a()
{
    char str[7] = "Hello";

    memmove(str + 1, str, 5);
    str[0] = 'X';

    printf("%s\n", str);
}

void b()
{
    char str[] = "Hello";

    memmove(str, str + 1, 5);

    printf("%s\n", str);
}

void c()
{
    char str1[] = "Hello";
    char str2[3];
    int i;

    strncpy(str2, str1, sizeof(str2));

    for (i = 0; i < 3; i++) {
        printf("%c", str2[i]);
    }
    printf("\n");
}

void d()
{
    char str1[] = "Hello";
    char str2[6];

    strcpy(str2, str1);

    printf("%s\n", str2);
}

int main()
{
    a();
    b();
    c();
    d();

    return 0;
}