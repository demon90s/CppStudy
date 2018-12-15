/*
    rewind(stream)
    移动文件位置指示器到 stream 的起始。
    还会清除文件尾和错误指示器。
*/

#include <stdio.h>

char str[20];

int main(void)
{
    FILE *f;
    char ch;

    f = fopen("example.dat", "w");
    if (!f) {
        perror("fopen");
        return 1;
    }
    for (ch = '0'; ch <= '9'; ch++) {
        fputc(ch, f);
    }
    fclose(f);

    f = fopen("example.dat", "r");
    fread(str, 1, 10, f);
    puts(str);

    rewind(f);
    fread(str, 1, 10, f);
    puts(str);
    fclose(f);

    return 0;
}