/* Computes the dimensional weight of a 12 * 10 * 8 box */

#include <stdio.h>

int main()
{
	int length, width, height, volume, weight;

	printf("Enter length of box: ");
	scanf("%d", &length);
	printf("Enter width of box: ");
	scanf("%d", &width);
	printf("Enter height of box: ");
	scanf("%d", &height);

	volume = length * width * height;

	weight = (volume + 165) / 166;

	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);

	return 0;
}
