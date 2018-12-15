/*
 * 修改程序 repdigit.c，要求修改后的程序可以让用户录入多于一个的数进行重复数字的判断。当用
 * 户录入的数小于或等于0时，程序终止。
 */

/*
 * 程序：检查数中重复出现的数字（p101）
 *
 * Enter a number: 28212
 * Repeated digit
 */

/* Checks numbers for repeated digits */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

int main()
{
	Bool digit_seen[10] = {0};
	int digit;
	int i;
	long int n, tmp_n;

	printf("Enter a number: ");
	scanf("%ld", &n);
	tmp_n = n;
	
	while (tmp_n > 0) {
		
		for (i = 0; i < 10; i++)
			digit_seen[i] = FALSE;

		while (n > 0) {
			digit = n % 10;
			if (digit_seen[digit])
				break;
			digit_seen[digit] = TRUE;
			n /= 10;
		}

		if (n > 0)
			printf("Repeated digit\n\n");
		else
			printf("No repeated digit\n\n");

		printf("Enter a number: ");
		scanf("%ld", &n);
		tmp_n = n;
	}

	return 0;
}
