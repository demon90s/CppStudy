/*
    编写一个名为 toupper 的程序，用来把文件中的所有字母转换成大写形式。（其他非字母字符不改变。）
    用户将采用命令行上输入文件名。

    toupper test.doc

    让程序 toupper 把输出写到 stdout 中。
*/

/*
    程序名就叫 ex_12.exe
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int c;
    FILE *fp;

    if (argc != 2) {
        printf("usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("fopen failure\n");
        return 2;
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(toupper(c));
    }

    fclose(fp);

    return 0;
}
