/*
 * 下面计算三角形面积的函数有两处错误。找出这些错误，并且说明修改它们的方法。（提示：公式没有
 * 错误）
 *
 * float triangle_area(float base, height)
 * float product;
 * {
 * 	product = base * height;
 * 	return (product / 2);
 * }
 */

/*
 * 形参列表写法错误，应该为 float base, float height
 * product 的声明位置有错，应该在大括号里
 */

#include <stdio.h>

float triangle_area(float base, float height)
{
	float product;
	product = base * height;
	return (product / 2);
}

int main()
{
	printf("%g\n", triangle_area(3, 4));

	return 0;
}
