/*
 * bar.c
 */

#include <stdio.h>

extern long int i;

extern int Get();
extern int GetAddress();

int main()
{
	i = 0;

	printf("i: %ld\n", i);
	printf("i from foo: %i\n", Get());

	printf("address of i: %p\n", &i);
	printf("address of i from foo: %p\n", GetAddress());

	return 0;
}
