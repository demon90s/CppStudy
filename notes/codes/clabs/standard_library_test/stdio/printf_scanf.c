/*
 * printf scanf
 * 格式化输入输出
 * 
 * d  	->	int
 * ld 	->	long int
 * lld	->	long long int
 * u	->	unsigned int
 * o	->	8进制整数
 * x	->	16进制整数
 * f	->  float or double, not for scanf double
 * lf	->	double for scanf
 * s	-> 	const char *
 * 
 * printf 返回写入的字符数，不包括空字符
 * scanf 返回成功匹配的个数
 */

#include <stdio.h>

/*
 * 读写 int 和 float
 */
void example1()
{
	int i;
	float f;

	printf("Enter integer: ");
	scanf("%d", &i);
	printf("%d\n", i);

	printf("Enter float: ");
	scanf("%f", &f);
	printf("%f\n", f);

	printf("Enter integer(至多两位整数): ");
	scanf("%2d", &i);
	printf("%d\n", i);
}

/*
 * 读写无符号整数 p80
 */
void example2()
{
	unsigned int u;

	printf("Enter unsigned interger(base 10): ");
	scanf("%u", &u);
	printf("%u\n", u);

	printf("Enter unsigned interger(base 8): ");
	scanf("%o", &u);
	printf("%o\n", u);

	printf("Enter unsigned interger(base 16): ");
	scanf("%x", &u);
	printf("%x\n", u);
}

/*
 * 读写短整数、长整数 p80
 */
void example3()
{
	short int s;
	long int l;

	printf("Enter short int: ");
	scanf("%hd", &s);
	printf("%hd\n", s);

	printf("Enter long int: ");
	scanf("%ld", &l);
	printf("%ld\n", l);
}

/*
 * 读写double p83
 */
void example4()
{
	double d;

	printf("Enter double: ");
	scanf("%lf", &d);
	printf("%f", d);
}

/*
 * 读写字符 p86
 */
void example5()
{
	char ch;
	
	printf("Enter char: ");
	scanf("%c", &ch);
	printf("%c", ch);
}

/*
 * 写字符串
 */
void example6()
{
	printf("%s\n", "Hello World");

	// %*s 代表字符串宽度是*
	// 这里就是6的宽度，因此输出 ###bar ，#代表空格
	int depth = 6;
	printf("%*s\n", depth, "bar");
}

/*
 * 写 size_t
 */
void example7()
{
	printf("sizeof int: %zu\n", sizeof(int));
}

int main()
{
	//example1();
	//example2();
	//example3();
	//example4();
	//example5();
	//example6();
	example7();

	return 0;
}
