/*
    fgetc(stream)

    从 stream 读取一个字符，如果遇到文件尾，则返回 EOF ，如果产生了错误，也返回 EOF
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    FILE *fp = fopen("example.dat", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);
    
    return 0;
}
