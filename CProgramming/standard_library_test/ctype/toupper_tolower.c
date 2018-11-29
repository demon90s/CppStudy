/*
 * toupper
 * 将小写字母改成大写字母
 * 
 * tolower
 * 将大写字母改成小写字母
 */

#include <ctype.h>
#include <stdio.h>

int main()
{
	/*char c = 'a';
	
	c = toupper(c);
	printf("%c\n", c);

	c = tolower(c);
	printf("%c\n", c);*/

	char *p;
    for (p = "aA0!"; *p != '\0'; p++) {
        printf("tolower('%c') is '%c'; ", *p, tolower(*p));
        printf("toupper('%c') is '%c'\n", *p, toupper(*p));
    }

	return 0;
}
