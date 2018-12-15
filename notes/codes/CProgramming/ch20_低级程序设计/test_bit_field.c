#include <stdio.h>

/*
    位域
*/

/*
    定义位域
    为了可移植性，位域应该声明为 unsigned int
*/
struct file_date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
};

int main(int argc, char const *argv[])
{
    printf("sizeof file_data: %u\n", sizeof(struct file_date));

    struct file_date fd;
    fd.day = 20;
    fd.month = 12;
    fd.year = 48;

    printf("file date: %d-%d-%d\n", 1970 + fd.year, fd.month, fd.day);

    return 0;
}
