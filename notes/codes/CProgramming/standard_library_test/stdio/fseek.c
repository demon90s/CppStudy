/*
    fseek(stream, offset, origin)

    设置文件流 stream 的文件指示器为 offset 所指向的位置。成功返回0，失败为非零。

    origin 可取值为 SEEK_SET, SEEK_CUR, SEEK_END ，分别代表起始位置、当前位置、结束位置。

    对于 offset ，如果 stream 以二进制模式打开，则 offset 取值任意；如果以文本模式打开，则仅支持0或者之前在同一个流上的 ftell 的返回值，且仅可用于
    SEEK_SET 的 origin 。
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

    // 读数组中第浮点数入
    fp = fopen("example.dat", "rb");
    
    if (fseek(fp, sizeof(double) * 2, SEEK_SET) != 0) {
        if (ferror(fp)) {
            perror("fseek");
            return 1;
        }
    }

    double B;
    fread(&B, sizeof(double), 1, fp);
    printf("%.1f\n", B);

    fclose(fp);

    return 0;
}
