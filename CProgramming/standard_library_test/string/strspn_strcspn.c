/*
    strspn
    size_t strspn(const char *s, const char *accept);
    返回一个段的长度，这个段由字符串s起始，到第一个不属于 accept 中的字符为止。

    strcspn
    size_t strcspn(const char *s, const char *accept);
    返回一个段的长度，这个段由字符串s起始，到第一个属于 accept 中的字符为止。
*/

#include <stdio.h>
#include <string.h>

void test_strspn()
{
    char str[] = "5566X88";
    size_t min_number_len = strspn(str, "0123456789");
    printf("min_number_len: %d\n", min_number_len); // 4
}

void test_strcspn()
{
    char str[] = "ABC987XXX";
    size_t min_NOT_number_len = strcspn(str, "0123456789");
    printf("min_NOT_number_len: %d\n", min_NOT_number_len);  // 3
}

int main(int argc, char const *argv[])
{
    test_strspn();
    test_strcspn();
    
    return 0;
}
