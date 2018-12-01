/*
    许多<string.h>的版本提供了额外的（非标准的）函数，例如下面列出的一些函数。使用标准C的特性
    给出每一个函数的实现。

    (a) strdup(s) 返回一个指针，该指针指向通过调用 malloc 函数获得的内存中保存的s的一个副本。
        如果没有足够的内存可以分配。则返回空指针。
    (b) stricmp(s1, s2) 与 strcmp 函数类似，但不考虑字母的大小写。
    (c) strlwr(s) 将s中的大写字母转换为小写字母，其他字符不变；返回s。
    (d) strrev(s) 反转字符从s中的字符顺序（除了空字符）；返回s。
    (e) strset(s, ch) 将s用 ch 的副本填充；返回s。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strdup(const char *s)
{
    char *p = malloc(sizeof(*s) * (strlen(s) + 1));
    if (p == NULL)
        return NULL;

    strcpy(p, s);
    return p;
}

void test_strdup()
{
    const char *str = "Hello world";
    char *p = strdup(str);
    if (p) {
        printf("dup str: %s\n", p);
        free(p);
    }
}

int stricmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (toupper(*s1) > toupper(*s2))
            return 1;
        else if (toupper(*s1) < toupper(*s2))
            return -1;
        s1++;
        s2++;
    }

    if (*s1 != '\0' && *s2 == '\0')
        return 1;
    else if (*s1 == '\0' && *s2 != '\0')
        return -1;
    else
        return 0;
}

void test_stricmp()
{
    char str1[128];
    char str2[128];
    int res;

    printf("Enter str1: ");
    scanf("%s", str1);
    printf("Enter str2: ");
    scanf("%s", str2);

    res = stricmp(str1, str2);
    if (res > 0)
        printf("%s > %s\n", str1, str2);
    else if (res < 0)
        printf("%s < %s\n", str1, str2);
    else
        printf("%s == %s\n", str1, str2);
}

char* strlwr(char *s)
{
    char *ret = s;
    while (*s != '\0') {
        if (isupper(*s)) {
            *s = tolower(*s);
        }
        s++;
    }
    return ret;
}

void test_strlwr()
{
    char str[128];

    printf("Enter str: ");
    scanf("%s", str);

    printf("to lower: %s\n", strlwr(str));
}

char* strrev(char *s)
{
    char *p = s;
    char *q = s + strlen(s) - 1;
    char tmp;

    while (p != q) {
        tmp = *p;
        *p = *q;
        *q = tmp;

        p++;
        q--;
    }

    return s;
}

void test_strrev()
{
    char str[128];

    printf("Enter str: ");
    scanf("%s", str);

    printf("reverse: %s\n", strrev(str));
}

char* strset(char *s, char ch)
{
    char *p = s;
    while (*p != '\0') {
        *p = ch;
        p++;
    }
    return s;
}

void test_strset()
{
    char str[128];

    printf("Enter str: ");
    scanf("%s", str);

    printf("after set: %s\n", strset(str, '*'));
}

int main()
{
    //test_strdup();
    //test_stricmp();
    //test_strlwr();
    //test_strrev();
    test_strset();

    return 0;
}