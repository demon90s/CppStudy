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

/*
 * strncmp 函数
 * int strncmp(const char *s1, const char *s2, size_t n);
 * 
 * 和 strncmp 函数一样，只不过当比较的字符数达到n个或其中任意一个字符数组遇到空字符时停止比较。
*/

/*
 * memcpy 函数
 * int memcmp(const void *ptr1, const void *ptr2, size_t num);
 * 
 * 比较 ptr1 和 ptr2 的 num 个字节是否相等。
 * 如果相等，返回0，否则如果第一个不相等的字节中， ptr1 的大则返回大于0的值， ptr1 的小则返回小于0的值。
 * 
 */

#include <string.h>
#include <stdio.h>

void test_strcmp()
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
}

void test_strncmp()
{
	char s1[] = "Hello Man";
	char s2[] = "Hi guy";

	int res;

	res = strncmp(s1, s2, 1);

	if (res == 0) {
		printf("s1 == s2\n");
	}
	else if (res < 0) {
		printf("s1 < s2\n");
	}
	else {
		printf("s1 > s2\n");
	}
}

void test_memcmp()
{
	char s1[] = "Hello Man";
	char s2[] = "Hello Min";

	int res;

	res = memcmp(s1, s2, sizeof(s1));

	if (res == 0) {
		printf("s1 == s2\n");
	}
	else if (res < 0) {
		printf("s1 < s2\n");
	}
	else {
		printf("s1 > s2\n");
	}
}

int main()
{
	//test_strncmp();
	test_memcmp();
	return 0;
}
