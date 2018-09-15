/*
通过下列方法缩写程序dweight.c: (1)用初始化语句替换对变量height、length和width的赋值语句；
(2)去掉变量weight，在最后的printf语句中计算(valoume + 165) / 166。
*/

/* Computes the dimensional weight of a 12 * 10 * 8 box */

#include <stdio.h>

int main()
{
	int length = 12, width = 10, height = 8, volume;

	volume = length * width * height;

	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);

	return 0;
}
