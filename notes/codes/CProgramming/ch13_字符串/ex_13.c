/*
 * 在本章的末尾“问与答”小节说明了利用数组下标的方式来编写 strcmp 函数的方法。请用指针算术
 * 运算的方法来修改此函数。
 */

#include <stdio.h>

int strcmp_(char *s, char *t)
{
	while (*s == *t) {
		if (*s == '\0')
			return 0;

		s++;
		t++;
	}
	return *s - *t;
}

int main()
{
	printf("%d\n", strcmp_("Hello", "Hi"));
	printf("%d\n", strcmp_("Hi", "Hi"));
	printf("%d\n", strcmp_("Hi", "Hello"));

	return 0;
}
