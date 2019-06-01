/*
    扩充 canopen 程序，以便用户可以把任意数量的文件名放置在命令行中：

    canopen foo bar baz

    这个程序应该为每个文件分别显示出 can be opened 消息或者 can't be opened 消息。如果命令
    行中没有参数，那么程序应该返回2；如果无法打开任何文件，那么程序返回1；如果可以打开所有文件，
    程序应返回0.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    int i;
    int opened_times;
    if (argc < 2) {
        printf("usage: canopen filename\n");
        return 2;
    }

    opened_times = 0;
    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
        }
        else {
            printf("%s can be opened\n", argv[i]);
            opened_times++;
        }
        
        fclose(fp);
    }

    if (opened_times == 0) return 1;

    if (opened_times < argc - 1) return 3;

    return 0;
}
