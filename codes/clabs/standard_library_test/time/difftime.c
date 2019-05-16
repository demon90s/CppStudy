/*
    double difftime(time_t time1, time_t time2);

    返回 time1 和 time2 之间按秒衡量的差值。经过测试, 尽管返回类型是 double , 但是实际是一个整数值
*/

#include <time.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    time_t start_time = time(NULL);

    int loops= 0;
    while (loops++ < 30000) {
        FILE *tmp = tmpfile();
        fputs("Hello, World", tmp);
        fclose(tmp);
    }
    
    time_t end_time = time(NULL);
    printf("Processor time used: %g sec.\n", difftime(end_time, start_time));
    
    return 0;
}