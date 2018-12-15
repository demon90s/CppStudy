/*
    编写 fseek 函数的调用来在二进制文件中执行下列文件定位操作，其中，二进制文件的数据以64字节
    “记录”的形式进行排列。采用 fp 作为下列每种情况中的文件指针。
    (a) 移动到记录n的开始处（假设文件中的首记录记为0）。
    (b) 移动到文件中最后一条记录的开始处。
    (c) 向前移动一条记录。
    (d) 向后移动两条记录。
*/

#include <stdio.h>

#define LEN 5

int main(int argc, char const *argv[])
{
    // 准备浮点值的数组
    double A[LEN] = {1., 2., 3., 4., 5.};
    double b;

    // 写入数组到文件
    FILE *fp = fopen("example.dat", "wb");
    fwrite(A, sizeof(double), LEN, fp);
    fclose(fp);

    // 读数组中第浮点数入
    fp = fopen("example.dat", "rb");
    
    /* a */
    fseek(fp, 0, SEEK_SET);
    fread(&b, sizeof(b), 1, fp);
    printf("a: %f, record: %d\n", b, ftell(fp) / sizeof(double));

    /* b */
    fseek(fp, -1 * sizeof(double), SEEK_END);
    fread(&b, sizeof(b), 1, fp);
    printf("b: %f, record: %d\n", b, ftell(fp) / sizeof(double));

    /* c */
    fseek(fp, -1 * sizeof(double), SEEK_CUR);
    fread(&b, sizeof(b), 1, fp);
    printf("c: %f, record: %d\n", b, ftell(fp) / sizeof(double));

    /* d */
    rewind(fp);
    fseek(fp, 2 * sizeof(double), SEEK_CUR);
    fread(&b, sizeof(b), 1, fp);
    printf("d: %f, record: %d\n", b, ftell(fp) / sizeof(double));

    fclose(fp);

    return 0;
}
