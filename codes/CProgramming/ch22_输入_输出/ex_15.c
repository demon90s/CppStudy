/*
    20.1节中的程序 xor 拒绝对原始格式或加密格式中是控制字符的字节进行加密。现在可以摆脱这种限制了。
    修改此程序使输入文件名和输出文件名都是命令行的参数。以二进制形式打开这两个文件，并且把用来检查
    原始字符或加密字符是否是控制字符的判断删除。
*/

#include <ctype.h>
#include <stdio.h>

#define KEY '&'

int main(int argc, char const *argv[])
{
    int orig_char, new_char;
    FILE *in_fp, *out_fp;

    if (argc != 3) {
        printf("usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    in_fp = fopen(argv[1], "rb");
    if (!in_fp) {
        printf("fopen %s failure\n", argv[1]);
        return 2;
    }
    out_fp = fopen(argv[2], "wb");
    if (!out_fp) {
        fclose(in_fp);
        printf("fopen %s failure\n", argv[2]);
        return 3;
    }

    while ((orig_char = fgetc(in_fp)) != EOF) {
        new_char = orig_char ^ KEY;
        fputc(new_char, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);

    return 0;
}