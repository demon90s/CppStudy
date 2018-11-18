/*
    假设f是下列函数。如果在此之前f从没有被调用过，那么f(10)的值是多少呢？如果在此之前f已经
    被调用过5次了，那么f(10)的值又是多少呢？

    int f(int i)
    {
        static int j = 0;
        return i * j++;
    }
*/

/*
    如果从未被调用过，那么 f(10) 的结果是：0
    如果在此之前f已经被调用过5次，那么 f(10) 的结果是：50
*/

#include <stdio.h>

int f(int i)
{
    static int j = 0;
    return i * j++;
}

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < 5; i++)
        f(10);

    printf("%d\n", f(10));
    
    return 0;
}
