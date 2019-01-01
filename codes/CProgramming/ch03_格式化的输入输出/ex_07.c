/*
 * 假设 scanf 函数调用的格式如下：
 * scanf("%d%f%d", &i, &x, &j);
 * 如果用户录入如下信息：
 * 10.3 5 6
 * 调用执行后，变量i、x和j的值分别是多少？（假设变量i和变量j都是 int 型，而变量x是 float 型。）
 */

#include <stdio.h>

int main()
{
	int i, j;
	float x;

	scanf("%d%f%d", &i, &x, &j);
	printf("%d %f %d\n", i, x, j); // i = 10, x = 0.3, y = 5

	return 0;
}
