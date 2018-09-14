/*
 * 如果i*i超出了 int 型的最大取值，那么6.3节的程序 square2.c 将失败（通常会显示奇怪的答案）。
 * 运行程序，并且确定导致失败的n的最小值。尝试把变量i的类型改成 short int 类型，并且再次
 * 运行程序。（不要忘记更新 printf 函数调用中的转换说明！）然后尝试改换成 long int 类型。从这
 * 些实验中，你能总结出在你的机器上用于存储整型的位数的多少吗？
 */

/*
 * int 32位
 * short int 16位
 * long int 64位
 *
 * PS: 不太好用实验的方法总结出来，最好的方式是直接用 sizeof 运算符确定
 */

#include <stdio.h>

int main()
{
	int i, n;
	long int check;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	for (i = 1; i <= n; ++i) {
		check = i;
		if (i * i != check * check) {
			printf("hit invalid i: %d\n", i);
			break;
		}

		printf("%10d%10d\n", i, i * i);
	}

	printf("bit count of int: %lu\n", sizeof(int) * 8);
	printf("bit count of short int: %lu\n", sizeof(short int) * 8);
	printf("bit count of long int: %lu\n", sizeof(long int) * 8);

	return 0;
}
