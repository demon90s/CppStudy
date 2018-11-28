/*
    在进行文件内容压缩的众多方法中，最简单快捷的方法之一是行程长度编码方式。这种方法通过一对
    字节替换相同的字节序列来进行文件的压缩：重复计数后面跟着重复的字节。例如，假设文件以下列
    字节序列开始进行压缩（以十六进制形式显示）：
    46 6f 6f
    压缩后的文件将包含下列字节：
    01 46 02 6f
    如果原始文件包含许多相同字节的长序列，那么行程长度编码的方法非常适用。最差的情况是行程长度编码
    可能实际上是文件长度的两倍。

    (a) 请编写名为 comp 的程序，此程序使用行程长度编码方法来压缩文件。为了运行程序 comp ,将使用
    下列格式的命令行：
    comp 原始文件 压缩后的文件
    如果压缩后的文件没有扩大，那么程序 comp 将添加扩展名 .rle 。例如，命令
    comp foo bar
    将会使程序 comp 创建名为 bar.rle 的文件，并且把文件 foo 的压缩版本写到此文件中。（程序 comp
    将在文件 bar.rle 开始处保存文件 foo 的名字。）提示：练习16中的程序 hexdump 可以用来调试/

    (b) 请编写名为 uncomp 的程序，此程序是程序 comp 的反向操作。程序 uncomp 的命令行格式为：
    uncomp 压缩后的文件
    如果压缩后的文件没有扩充，那么程序 uncomp 将添加扩展名 .rle 。例如，命令
    uncomp bar
    将会使程序 uncomp 打开文件 bar.rle ，并且写出文件内容的未压缩版，同时把文件的名字保存在 bar.rle
    的开始处。
*/

#include <stdio.h>

void comp(const char *in, const char *out)
{
    FILE *in_fp, *out_fp, *out_fp2;
    int ch_store, ch_cur;
    int count_read = 0, count_write = 0;
    unsigned char count_store;

    in_fp = fopen(in, "rb");
    if (!in_fp) {
        printf("fopen %s failed\n", in);
        return;
    }

    out_fp = fopen(out, "wb+");
    if (!out_fp) {
        fclose(in_fp);
        printf("fopen %s failed\n", out);
        return;
    }

    ch_cur = fgetc(in_fp);
    ch_store = ch_cur;
    count_store = 1;
    count_read = 1;
    while (ch_cur != EOF) {
        ch_cur = fgetc(in_fp);
        ++count_read;

        if (count_store >= 255 || ch_cur != ch_store) {
            fputc(count_store, out_fp);
            fputc(ch_store, out_fp);
            count_store = 1;
            ch_store = ch_cur;
            count_write += 2;
        }
        else {
            count_store++;
        }
    }

    if (count_read > count_write) {
        char buffer[128];
        snprintf(buffer, 128, "%s.rle", out);
        out_fp2 = fopen(buffer, "wb");
        if (out_fp2)
        {
            rewind(out_fp);
            fputs(in, out_fp2);
            while ((ch_cur = fgetc(out_fp)) != EOF) {
                fputc(ch_cur, out_fp2);
            }
            fclose(out_fp2);
        }
    }

    fclose(in_fp);
    fclose(out_fp);
}

void uncomp(const char *in)
{
    FILE *in_fp, *tmp_fp, *out_fp;
    int count, i;
    int count_read, count_write;
    int ch;
    char buffer[128];
    snprintf(buffer, 128, "%s.rle", in);
    
    in_fp = fopen(in, "rb");
    if (!in_fp) {
        printf("fopen failure\n");
        return;
    }

    tmp_fp = tmpfile();

    do {
        count = fgetc(in_fp);
        ch = fgetc(in_fp);
        for (i = 0 ; i < count; ++i) {
            printf("%02x ", ch);
            fputc(ch, tmp_fp);
            count_write++;
        }
        count_read += 2;
    } while (ch != EOF);

    if (count_write > count_read) {
        out_fp = fopen(buffer, "wb");
        if (out_fp) {
            fputs(in, out_fp);
            rewind(tmp_fp);
            while ((ch = fgetc(tmp_fp)) != EOF) {
                fputc(ch, out_fp);
            }
            fclose(out_fp);
        }
    }

    fclose(in_fp);
    fclose(tmp_fp);
}

int main(int argc, char const *argv[])
{
    /* a */
    /*{
        if (argc != 3) {
            printf("usage: %s <in_file> <out_file>\n", argv[0]);
            return 1;
        }

        comp(argv[1], argv[2]);
    }*/

    /* b */
    {
        if (argc != 2) {
            printf("usage: %s <in_file>\n", argv[0]);
            return 1;
        }

        uncomp(argv[1]);
    }
    
    return 0;
}
