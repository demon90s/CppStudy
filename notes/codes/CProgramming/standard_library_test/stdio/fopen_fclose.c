/*
    fopen
    fopen(file, mode)
    根据 mode 打开文件 file，返回其文件指针 FILE*

    mode 可以是：
    - r, rb: 打开文件用于读，若文件存在就从头读，不存在则失败
    - w, wb: 打开文件用于写，若文件存在就销毁内容，不存在则创建新文件
    - a, ab: 打开文件用于追加，若文件存在就写到结尾，不存在则创建新文件
    - r+, rb+: 打开文件用于读和写，若文件存在就从头读，不存在就错误
    - w+, wb+: 打开文件用于读和写，若文件存在就销毁内容，不存在则创建新文件
    - a+, ab+: 打开文件用于读和写，若文件存在就写到结尾，不存在则创建新文件

    其中后缀b代表打开的是二进制文件。

    失败返回 NULL 。

    fclose
    fclose(stream)
    关闭文件，stream 必须来自 fopen 或 freopen 。如果成功关闭，返回0，否则返回错误代码 EOF 。
*/

#include <stdio.h>

#define FILE_NAME "example.dat"

int main(int argc, char const *argv[])
{
    FILE *fp;

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("Can't open %s\n", FILE_NAME);
        return 1;
    }
    else {
        printf("Open %s success\n", FILE_NAME);
    }

    /* ... */

    if (0 != fclose(fp)) {
        printf("Close %s failure\n", FILE_NAME);
    }
    else {
        printf("Close %s success\n", FILE_NAME);
    }
    
    return 0;
}
