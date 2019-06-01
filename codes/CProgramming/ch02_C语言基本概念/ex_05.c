/*
 * 编写一个计算球体体积的程序，其中球体半径为10m，参考公式v=4/3πr3。注意，分数4/3应写为
 * 4.0/3.0。（如果分数写成4/3，会产生什么结果？）
 */

/*
 * 如果写成4/3，那么结果恒等于1，不是正确的结果。
 */

#include <stdio.h>

#define PI 3.14

int main()
{
	float radius, volume;

	radius = 10;
	volume = 4.0 / 3.0 * PI * radius * radius * radius;

	printf("volume: %.2f\n", volume);

	return 0;
}
