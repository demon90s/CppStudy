/*
    编写程序对由 invent 程序存储的含有零件记录的两个文件进行合并（见练习19）。假设每个文件中的记录都是根据零件编号进行排序的，
    而且希望结果文件也应是排序好的。如果两个文件都拥有相同编号的零件，那么要对记录中存储的数量进行合并。（作为连贯的检查，程序
    要比较零件的名称，并且在不匹配时显示出错信息。）程序在命令行上要包含输入文件名以及合并后的文件名。
*/

#include <stdio.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

typedef struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} Part;

int main(int argc, char const *argv[])
{
    const char* in_file1, *in_file2, *out_file;
    FILE *in_fp1, *in_fp2, *out_fp;
    Part in_part1[MAX_PARTS], in_part2[MAX_PARTS], out_part[MAX_PARTS];
    int in_part1_count, in_part2_count, out_part_count;
    int i, j;
    Part tmp_part;

    /* 获得输入的文件名和输出的文件名 */
    if (argc != 4) {
        printf("usage: %s <in_file1> <in_file2> <out_file>\n", argv[0]);
        return 1;
    }
    in_file1 = argv[1];
    in_file2 = argv[2];
    out_file = argv[3];

    /* 读取两个文件 */
    in_fp1 = fopen(in_file1, "rb");
    if (!in_fp1) {
        printf("fopen %s failed\n", in_file1);
        return 2;
    }

    in_fp2 = fopen(in_file2, "rb");
    if (!in_fp2) {
        fclose(in_fp1);
        printf("fopen %s failed\n", in_file2);
        return 2;
    }

    /* 读取文件的内容到数组，关闭文件 */
    in_part1_count = fread(in_part1, sizeof(in_part1[0]), MAX_PARTS, in_fp1);
    in_part2_count = fread(in_part2, sizeof(in_part2[0]), MAX_PARTS, in_fp2);

    fclose(in_fp1);
    fclose(in_fp2);

    /* 进行合并数组，从小到大排序 */
    out_part_count = 0;
    i = 0;
    j = 0;
    while ((i < in_part1_count || j < in_part2_count) && out_part_count < MAX_PARTS) {
        if (i == in_part1_count) {
            tmp_part = in_part2[j++];
        }
        else if (j == in_part2_count)  {
            tmp_part = in_part1[i++];
        }
        else if (in_part1[i].number < in_part2[j].number) {
            tmp_part = in_part1[i++];
        }
        else if (in_part1[i].number > in_part2[j].number) {
            tmp_part = in_part2[j++];
        }
        else if (in_part1[i].number == in_part2[j].number) {
            if (strcmp(in_part1[i].name, in_part2[j].name) == 0) {
                tmp_part = in_part1[i];
                tmp_part.on_hand += in_part2[j].on_hand;
                i++;
                j++;
            }
            else {
                printf("part1[%d %s] not compare with part2[%d %s], ignored merge!\n", 
                    in_part1[i].number, in_part1[i].name,
                    in_part2[j].number, in_part2[j].name);
                i++;
                j++;
                continue;
            }
        }

        out_part[out_part_count++] = tmp_part;
    }

    if (out_part_count <= 0) {
        printf("no part to merge\n");
        return 2;
    }
    
    /* 输出到文件，关闭输出文件 */
    out_fp = fopen(out_file, "wb");
    if (!out_fp) {
        printf("fopen %s failed\n", out_file);
        return 3;
    }

    fwrite(out_part, sizeof(out_part[0]), out_part_count, out_fp);

    fclose(out_fp);

    return 0;
}
