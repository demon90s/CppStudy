/*
    fputs(str, stream)
    向 stream 输出 str
    与 puts 不同， fputs 不会自动添加换行

    出现错误时，返回 EOF ，否则返回非负的数
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("example.dat", "w");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    fputs("Hello World", fp);

    fclose(fp);
    return 0;
}
