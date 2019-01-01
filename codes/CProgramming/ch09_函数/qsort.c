/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>

#define LEN 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main()
{
	int a[LEN], i;

	printf("Enter %d numbers to be sorted: ", LEN);
	for (i = 0; i < LEN; ++ i)
	{
		scanf("%d", &a[i]);
	}

	quicksort(a, 0, LEN - 1);

	printf("In sorted order:");
	for (i = 0 ; i < LEN; ++ i)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}

void quicksort(int a[], int low, int high)
{
	int middle;

	if (low >= high) return;
	middle = split(a, low, high);

	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
	int part_element = a[low];

	for (;;)
	{
		while (low < high && part_element <= a[high])
		{
			high--;
		}
		if (low >= high) break;
		a[low++] = a[high];

		while (low < high && a[low] <= part_element)
		{
			low++;
		}
		if (low >= high) break;
		a[high--] = a[low];
	}

	a[high] = part_element;
	return high;
}
