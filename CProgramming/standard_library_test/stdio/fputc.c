/*
    int fputc(c, stream);

    向流 stream 写一个字符c

    返回写入的字符，如果出现错误，返回 EOF ，并为流设置错误指示器
*/

#include <stdio.h>

int main()
{
    FILE *fp = fopen("example.dat", "w");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    int c = 'a';
    do {
        fputc(c++, fp);
    } while (c <= 'z');

    fclose(fp);

    return 0;
}