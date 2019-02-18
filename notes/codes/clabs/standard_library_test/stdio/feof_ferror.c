/*
    feof(stream)
    如果 stream 设置了文件末尾指示器，那么返回非零值

    ferror(stream)
    如果 stream 产生了错误，那么返回非零值
*/

#include <stdio.h>

/* 搜索以某个整数起始的行 */
int find_int(const char* filename, int *ptr)
{
    FILE *fp = fopen(filename, "r");
    int line = 1;

    if (fp == NULL)
        return -1;

    while (fscanf(fp, "%d", ptr) != 1) {
        if (ferror(fp)) {
            fclose(fp);
            return -2; /* input error */
        }
        if (feof(fp)) {
            fclose(fp);
            return -3; /* integer not found */
        }
        /* 剩余的失败情况，只能是 fscanf 没有匹配 */
        fscanf(fp, "%*[^\n]"); /* 跳过全部字符直到下一个换行符为止 */
        line++; 
    }

    fclose(fp);
    return line;
}

int main(int argc, char const *argv[])
{
    int number;
    int line = find_int("example.dat", &number);
    printf("line: %d, number: %d\n", line, number);

    return 0;
}
