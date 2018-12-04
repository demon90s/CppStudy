/*
    (a) 编写一个程序，使它可以调用 rand 函数1000次并且显示函数返回值的最低位（如果返回值
        是偶数，则为0；如果返回值为奇数，则为1。）你看到过什么模式吗？（ rand 的返回值的
        最后几位往往不是特别随机的。 ）

    (b) 如何改进 rand 函数的随机性，使它可以在一个小范围内产生数？
*/

/*
    看到过什么模式吗？这句话问的是什么，我没有搞懂。

    通过使用 % 100 这样的操作，可以产生范围小的数，但是能否改进其随机性，我不是很肯定。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int loop = 0;
    int num;
    int hit[2] = {0};
    srand(time(NULL));

    while (loop++ < 1000) {
        num = rand() % 100;
        printf("%d\t%s\n", num, num % 2 == 0 ? "0" : "1");\
        if (num % 2 == 0) {
            hit[0]++;
        }
        else {
            hit[1]++;
        }
    }

    printf("hit even number times: %d\n", hit[0]);
    printf("hit odd number times: %d\n", hit[1]);
    
    return 0;
}
