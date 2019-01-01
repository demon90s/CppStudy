/*
    编写一个程序，将文件从标准输入复制到标准输出，删除所有空行（仅包含空白字符的行）。
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_blank_line(const char *line)
{
    if (line[strlen(line) - 1] != '\n')
        return 0;

    while (*line != '\0') {
        if (!isspace(*line))
            return 0;

        line++;
    }
    return 1;
}

int main()
{
    char buffer[32];

    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (is_blank_line(buffer))
            continue;
        fputs(buffer, stdout);
    }
  
    return 0;
}