/*
 * 修改程序 repdigit.c ，要求修改后的程序可以显示出一张列表，表内显示出每种数字在数中出现的
 * 次数：
 *
 * Enter a number: 41271092
 * Digit:		0 1 2 3 4 5 6 7 8 9
 * Occurrences: 1 2 2 0 1 0 0 1 0 1
 */

/*
 * 程序：检查数中重复出现的数字（p101）
 *
 * Enter a number: 28212
 * Repeated digit
 */

/* Checks numbers for repeated digits */

#include <stdio.h>

typedef int Bool;

int main()
{
	int digit_seen_times[10] = {0};
	int digit;
	long int n;
	int i;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		++digit_seen_times[digit];
		n /= 10;
	}

	printf("Digit:\t\t");
	for (i = 0; i < 10; i++)
		printf(" %d", i);
	printf("\n");

	printf("Occurrences:\t");
	for (i = 0; i < 10; i++) {
		printf(" %d", digit_seen_times[i]);
	}
	printf("\n");

	return 0;
}
