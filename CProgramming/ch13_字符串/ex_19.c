/*
 * 编写名为 sum.c 的程序，用来对命令行参数求和。假设参数都是整数。如果按下述方式执行程序：
 *
 * sum 8 24 62
 *
 * 产生的输出应为
 *
 * Total: 94
 *
 * 提示：用 atoi 函数把每个命令行参数从字符串格式转换为整数格式。
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int sum;
	int i;

	for (i = 1; i < argc; i++)
		sum += atoi(argv[i]);

	printf("Total: %d\n", sum);

	return 0;
}
