/*
    sprintf(str, format, ...)
    将格式串 format 的内容拷贝到字符数组 str 里面，并为其添加空字符，返回存储字符的数量（不计入空字符）。

    sscanf(str, format, ...)
    将 str 的内容拷贝到格式串 format 的转换说明符对应的变量上面，返回匹配成功的数量。
*/

#include <stdio.h>

void test_sprintf()
{
    char buffer[6];
    sprintf(buffer, "%s", "hello");

    printf("buffer: %s\n", buffer);
}

void test_sscanf()
{
    const char* date = "09-19-2015";
    int month, day, year;

    if (sscanf(date, "%d/%d/%d", &month, &day, &year) == 3) {
        printf("year: %d, month: %d, day: %d", year, month, day);
    }
    else if (sscanf(date, "%d-%d-%d", &month, &day, &year) == 3) {
        printf("year: %d, month: %d, day: %d", year, month, day);
    }
    else {
        printf("Date not in the proper format!\n");
    }
}

int main(int argc, char const *argv[])
{
    test_sprintf();
    test_sscanf();

    return 0;
}
