/*
 * 编写程序，要求提示用户输入一个数n，然后显示出1~n的所有偶数平方。例如，如果用户输入10，
 * 那么程序员应该显示出下列内容：
 *
 * 4
 * 16
 * 36
 * 64
 * 100
 */

#include <stdio.h>

int main()
{
	int n, i;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 2; i <= n; i += 2) {
		printf("%d\n", i * i);
	}

	return 0;
}
