/*
 * 修改程序 repdigit.c ，要求修改后的程序可以显示出重复的数字（如果有的话）：
 *
 * Enter a number: 939577
 * Repeated digit(s): 7 9
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

	printf("Repeated digit(s):");
	for (i = 0; i < 10; i++) {
		if (digit_seen_times[i] > 1)
			printf(" %d", i);
	}
	printf("\n");

	return 0;
}
