/*
    编写一个名为 fact 的程序，通过把任意数量的文件写到标准输出中而把这些文件一个接一个的“拼接”
    起来，而且文件之间没有间隙。例如，下列命令将在屏幕上显示文件 f1.c f2.c f3.c ：

    fcat f1.c f2.c f3.c

    如果任何文件都无法打开，那么程序 fcat 应该发出错误信息。提示：因为每次只可以打开一个文件，
    所以程序 fcat 只需要一个文件指针变量。一旦对一个文件完成操作，程序 fcat 在打开下一个文件时
    可以使用同一个文件指针变量。
*/

/*
    PS: 程序名就叫 ex_13.exe
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, opened_count = 0;
    int ch;
    FILE *fp;
    if (argc < 2) {
        fprintf(stderr, "usage: ex_13.exe <file_list>");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (!fp) continue;

        while ((ch = fgetc(fp)) != EOF)
            putchar(ch);

        opened_count++;
        fclose(fp);
    }

    if (opened_count == 0) {
        fprintf(stderr, "no file opened\n");
        return 2;
    }
    
    return 0;
}
