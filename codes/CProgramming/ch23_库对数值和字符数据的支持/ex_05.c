/*
    编写一个程序，将文件从标准输入复制到标准输出，将每个单词的首字母大写。
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch;
    int need_check;

    need_check = 1;
    while ((ch = fgetc(stdin)) != EOF) {
        if (!isalpha(ch) && ch != '_')
            need_check = 1;

        if (need_check && isalpha(ch)) {
            ch = toupper(ch);
            need_check = 0;
        }

        fputc(ch, stdout);
    }
  
    return 0;
}