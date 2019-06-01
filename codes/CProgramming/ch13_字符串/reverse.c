/*
 * 把命令行参数反序输出。如果按下述方式执行程序：
 *
 * reverse void and null
 *
 * 产生的输出应为
 *
 * null and void
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	int i;

	for (i = argc - 1; i >= 1; i--) {
		printf("%s ", argv[i]);
	}

	return 0;
}
