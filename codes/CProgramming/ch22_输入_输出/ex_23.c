/*
    编写一个名为 dispdate 的程序，用来从命令行读取数据，并且按照下列格式显示出来：

    September 13, 1995

    允许用户以9-13-95或者9/13/95的形式录入日期，并假设日期中没有空格。如果没有按照指定格式
    录入日期，那么程序显示出错信息。提示：使用 sscanf 函数从命令行参数中截取出年、月、日。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int year, month, day;
    const char* month_str[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    if (argc < 2) {
        printf("usage: %s <date>\n", argv[0]);
        printf("example: %s 9-13-95\n");
        return 1;
    }

    if (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) == 3) {
    }
    else if (sscanf(argv[1], "%d/%d/%d", &month, &day, &year) == 3) {
    }
    else {
        printf("format error, example: 9-13-95\n");
        return 2;
    }

    printf("%s %d, %d\n", month_str[month - 1], day, year + 1900);

    return 0;
}
