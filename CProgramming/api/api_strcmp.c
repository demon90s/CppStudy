/*
 * strcmp 函数：
 *
 * int strcmp(const char *s1, const char *s2);
 *
 * strcmp 函数比较字符串 s1 和字符串 s2 ，然后根据 s1 是否小于、等于、或大于 s2 ，
 * 函数返回小于、等于、或大于0的值。
 *
 * strcmp 函数利用字段顺序进行字符串比较，如果前面所有字符一致，长度短的字符串小。
 */

#include <string.h>
#include <stdio.h>

int main()
{
	char s1[] = "Hello Man";
	char s2[] = "Hi guy";

	int res;

	res = strcmp(s1, s2);

	if (res == 0) {
		printf("s1 == s2\n");
	}
	else if (res < 0) {
		printf("s1 < s2\n");
	}
	else {
		printf("s1 > s2\n");
	}

	return 0;
}
