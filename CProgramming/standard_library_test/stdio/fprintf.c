/*
    fprintf(stream, format, ...)

    向 stream 写输出
    若成功返回写入的字符数，出错返回负值。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num_write = fprintf(stdout, "Hello\n");
    printf("you write %d character(s)\n", num_write);
    
    return 0;
}
