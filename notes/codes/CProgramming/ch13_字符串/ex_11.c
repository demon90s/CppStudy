/*
 * 在执行下列语句后，字符串s1与s2的值各是多少？
 *
 * strcpy(s1, "computer");
 * strcpy(s2, "science");
 * if (strcmp(s1, s2) < 0)
 * 	strcat(s1, s2);
 * else
 * 	strcat(s2, s1);
 * s2[strlen(s2)-6] = '\0';
 */

/*
 * s1: computerscience
 * s2: s
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[20], s2[20];

	strcpy(s1, "computer");
	strcpy(s2, "science");
	if (strcmp(s1, s2) < 0)
		strcat(s1, s2);
	else
		strcat(s2, s1);
	s2[strlen(s2)-6] = '\0';

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

	return 0;
}
