/*
 * 思考下面这个“神秘的”函数：
 * void pb(int n)
 * {
 * 	if (n != 0) {
 * 		pb(n / 2);
 * 		putchar('O' + n % 2);
 * 	}
 * }
 *
 * 手动跟踪函数的执行，然后编写程序调试此函数，把用户录入的数传递给此函数。函数做了什么？
 */

/*
 * 递归输出一些内容，每次调用输出O或者P
 */

#include <stdio.h>

void pb(int n)
{
	if (n != 0) {
		pb(n / 2);
		putchar('O' + n % 2);
	}
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	pb(n);

	return 0;
}
