/*
 * 说明下列每对 scanf 格式串是否等价？如果不等价，请指出它们的差异。
 */

#include <stdio.h>

int main()
{
	int i, j, k;
	float x, y;

	// (a) "%d" 与 " %d" 等价
	//scanf("%d", &i); printf("%d\n", i);
	//scanf(" %d", &i); printf("%d\n", i);

	// (b) "%d-%d-%d" 与 "%d -%d -%d" 不等价，不能用第二个格式串的输入代替第一个
	//scanf("%d-%d-%d", &i, &j, &k); printf("%d %d %d\n", i, j, k);
	//scanf("%d -%d -%d", &i, &j, &k); printf("%d %d %d\n", i, j, k);
	
	// (c) “%f” 与 "%f " 不等价，第二个格式串的末尾是空格，必须读取一个非空白字符
	//scanf("%f", &x); printf("%f\n", x);
	//scanf("%f ", &x); printf("%f\n", x);

	// (d) "%f,%f" 与 "%f, %f" 等价
	scanf("%f,%f", &x, &y); printf("%f %f\n", x, y);
	scanf("%f, %f", &x, &y); printf("%f %f\n", x, y);
	

	return 0;
}
