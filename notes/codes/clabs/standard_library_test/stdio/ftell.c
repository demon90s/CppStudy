/*
    ftell(stream)

    返回流 stream 的文件位置指示器。
    若以二进制模式打开，那么此值是从文件开始的字节数。
    若以文本模式打开，那么值未指定，仅作为 fseek() 的输入才有意义。

    成功返回文件指示器，失败返回 EOF 。
*/

#include <stdio.h>

#define LEN 5

int main(int argc, char const *argv[])
{
    // 准备浮点值的数组
    double A[LEN] = {1., 2., 3., 4., 5.};

    // 写入数组到文件
    FILE *fp = fopen("example.dat", "wb");
    fwrite(A, sizeof(double), LEN, fp);
    fclose(fp);

    fp = fopen("example.dat", "rb");

    // 读取一个元素后，文件的指示器应该跳到第八个字节的位置，即第二个元素
    double B;
    fread(&B, sizeof(double), 1, fp);

    long pos = ftell(fp);
    printf("pos: %ld\n", pos);

    fclose(fp);

    return 0;
}
