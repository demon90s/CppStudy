/*
    请编写下列函数。函数 sum(g, i, j) 的调用应该返回 g(i) + ... + g(j) 。

    int sum(int (*f)(int), int start, int end);
*/

#include <stdio.h>

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;
    while (start <= end) {
        sum += f(start++);
    }
    return sum;
}

int func(int i)
{
    return i;
}

int main(int argc, char const *argv[])
{
    printf("sum(0 to 100): %d\n", sum(func, 0, 100));
    return 0;
}
