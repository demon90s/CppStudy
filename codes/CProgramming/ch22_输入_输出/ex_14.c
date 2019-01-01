/*
    让下列每一个程序都通过命令行获得文件名，并把输出写到 stdout 中。

    (a) 编写一个名为 cntchar 的程序，用来统计文本文件中字符的数量。
    (b) 编写一个名为 cntword 的程序，用来统计文本文件中单词的数量（所谓“单词”指的是不含空白字符的任意序列）。
    (c) 编写一个名为 cntline 的程序，用来统计文本文件中行的数量。
*/

/*
    PS: 直接写成函数
*/

#include <stdio.h>
#include <ctype.h>

void cntchar(const char *file_name)
{
    FILE *fp;
    int ch;
    int count = 0;
    fp = fopen(file_name, "r");

    if (!fp) {
        fprintf(stderr, "fopen failure\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }

    printf("character's count: %d\n", count);

    fclose(fp);
}

static int read_word(FILE *fp)
{
    int ch;

    while (isspace((ch = fgetc(fp))));
    if (ch == EOF) return 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) {
            break;
        }
    }

    return 1;
}

void cntword(const char *file_name)
{
    FILE *fp;
    int ch;
    int count = 0;
    fp = fopen(file_name, "r");

    if (!fp) {
        fprintf(stderr, "fopen failure\n");
        return;
    }

    while (read_word(fp)) {
        count++;
    }

    printf("word's count: %d\n", count);

    fclose(fp);
}

// 返回读取的行中的字符数
static int read_line(FILE *fp)
{
    int ch;
    ch = fgetc(fp);
    if (ch == EOF) return 0;

    while (ch != '\n' && ch != EOF) {
        ch = fgetc(fp);
    }

    return 1;
}

void cntline(const char *file_name)
{
    FILE *fp;
    int ch;
    int count = 0;
    fp = fopen(file_name, "r");

    if (!fp) {
        fprintf(stderr, "fopen failure\n");
        return;
    }

    while (read_line(fp)) {
        count++;
    }

    printf("line's count: %d\n", count);

    fclose(fp);
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("usage: %s file_name\n", argv[0]);
        return 1;
    }

    cntchar(argv[1]);
    cntword(argv[1]);
    cntline(argv[1]);
    return 0;
}
