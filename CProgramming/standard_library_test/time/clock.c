/*
    clock_t clock(void);

    返回处理器时间。它是一个 clock_t 类型。程序从执行开始后使用这个时间（在 windows 下测试，程序开始时为0）

    为了把这个时间转换成秒，需要除以 CLOCKS_PER_SEC 。
*/

#include <time.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    clock_t start_clock = clock();
    //printf("start_clock: %g\n", start_clock / (double)CLOCKS_PER_SEC);

    int loops= 0;
    while (loops++ < 10000) {
        FILE *tmp = tmpfile();
        fputs("Hello, World", tmp);
        fclose(tmp);
    }
    
    clock_t end_clock = clock();
    printf("Processor time used: %g sec.\n", (end_clock - start_clock) / (double)CLOCKS_PER_SEC);
    
    return 0;
}
