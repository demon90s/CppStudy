/*
 * 在执行下列语句后，字符串 str 的值是什么？
 *
 * strcpy(str, "tire-bouchon");
 * strcpy(&str[4], "d-or-wi");
 * strcat(str, "red?");
 */

/*
 * tired-or-wired?
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];

	strcpy(str, "tire-bouchon");
	strcpy(&str[4], "d-or-wi");
	strcat(str, "red?");

	printf("%s\n", str);

	return 0;
}
