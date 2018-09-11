/*
 * 请写出下面程序段的输出结果？（假设i是整型变量）
 */

/*
 * onetwo
 */

#include <stdio.h>

int main()
{
	int i;

	i = 1;
	switch (i % 3) {
		case 0: printf("zero");
		case 1: printf("one");
		case 2: printf("two");
	}

	putchar(10);

	return 0;
}
