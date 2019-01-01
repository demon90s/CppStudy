/*
 * 假设 scanf 函数调用的格式如下：
 * scanf("%f%d%f", &x, &i, &y);
 * 如果用户录入如下信息：
 * 12.3 45.6 789
 * 调用执行后，变量x、i和y的值分别是多少？（假设变量x和变量y都是 float 型，而变量i是 int 型。）
 */

#include <stdio.h>

int main()
{
	int i;
	float x, y;

	scanf("%f%d%f", &x, &i, &y);
	printf("%f %d %f\n", x, i, y); // x = 12.3, i = 45, y = 0.6

	return 0;
}
