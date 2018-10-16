/*
 * 下面程序的输出是什么？
 *
 * #include <stdio.h>
 *
 * main()
 * {
 * 	char s[] = "Hsjodi", *p;
 *
 * 	for (p = &s[5]; p >= s; p--) --*p;
 * 	puts(s);
 * 	return 0;
 * }
 */

/*
 * Grinch
 */

#include <stdio.h>

int main()
{
	char s[] = "Hsjodi", *p;
	for (p = &s[5]; p >= s; p--) --*p;
		puts(s);

	return 0;
}
