/*
 * 修改练习5中的程序，使用户可以自行录入球体的半径。
 */

#include <stdio.h>

#define PI 3.14

int main()
{
	float radius, volume;

	printf("Enter radius: ");
	scanf("%f", &radius);

	volume = 4.0 / 3.0 * PI * radius * radius * radius;

	printf("volume: %.2f\n", volume);

	return 0;
}
