/*
 * #include <stdlib.h>
 * int rand(void);
 * void srand(unsigned int seed);
 * 
 * 用来生成伪随机数。
 * 每次调用 rand ，它都返回一个 0~RAND_MAX 的数，这个数由 seed 产生。
 * 
 * seed通常定义成时间戳，比如 time(0) ，通过 srand 函数设置 seed 。
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int n;

	srand(time(0));

	n = rand() % 100;

	printf("rand n: %d\n", n);

	return 0;
}
