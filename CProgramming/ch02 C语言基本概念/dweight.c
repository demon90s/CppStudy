/* Computes the dimensional weight of a 12 * 10 * 8 box */

#include <stdio.h>

int main()
{
	int length, width, height, volume, weight;

	length = 12;
	width = 10;
	height = 8;

	volume = length * width * height;

	weight = (volume + 165) / 166;

	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);

	return 0;
}
