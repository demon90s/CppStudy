/*
    fgets(s, n, stream)

    从 stream 中读取字符串，在遇到换行符时停止，或者已经读入了n-1个字符时停止，如果读入了换行符，
    将其保存下来。

    如果出现了错误，或者存储字符前遇到了文件尾，那么返回空指针，否则返回s
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char buffer[32];
    FILE *fp = fopen("fgets.c", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (NULL != fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}
