/*
    fscanf(stream, format, ...)

    从 stream 中读取数据，存放到指定的位置上。
    返回读入并且赋值给实参的数据项数量，如果在能读取任何数据项之前发生输入失败，那么返回 EOF 。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("cfg.ini", "r");
    if (!fp) {
        fprintf(stderr, "fopen failure\n");
        return 1;
    }

    char name[32];
    int power;
    fscanf(fp, "name=%s", name);
    fscanf(fp, " power=%d", &power);

    printf("name: %s\n", name);
    printf("power: %d\n", power);

    fclose(fp);

    return 0;
}
