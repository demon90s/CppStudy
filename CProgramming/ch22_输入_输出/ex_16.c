/*
    编写一个名为 hexdump 的程序，以十六进制代码序列的形式显示文件中的字节，且每行显示20个代码
    （如下所示）。

    43 68 61 ....

    用户需要在命令行中指定文件名。请确保文件以"rb"模式打开。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    int ch;
    int count = 0;

    if (argc != 2)  {
        printf("usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("fopen failure\n");
        return 2;
    }

    while ((ch = fgetc(fp)) != EOF) {
        printf("%02x ", ch);
        count++;
        if (count % 20 == 0)
            printf("\n");
    }

    fclose(fp);

    return 0;
}
