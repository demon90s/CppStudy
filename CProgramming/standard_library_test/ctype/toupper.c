/*
 * toupper
 *
 * 将小写字母改成大写字母
 */

#include <ctype.h>
#include <stdio.h>

int main()
{
	int ch;
	printf("Enter a character: ");
	ch = getchar();

	ch = toupper(ch);

	printf("%c\n", ch);

	return 0;
}
