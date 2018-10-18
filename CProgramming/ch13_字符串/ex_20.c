/*
 * 改进程序 planets.c ，使它在比较命令行参数与 planets 数组中的字符串时忽略大小写。
 */

/*
 * planet.c
 *
 * Checks planet names
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

void ToUpper(const char* s, char *out)
{
	while (*s) {
		*out++ = toupper(*s++);
	}
}

int main(int argc, char *argv[])
{
	char *planets[] = {
		"Mercury",
		"Venus",
		"Earth",
		"Mars",
		"Jupiter",
		"Saturn",
		"Uranus",
		"Neptune",
		"Pluto",
	};

	int i, j;
	for (i = 1; i < argc; i++) {
		for (j = 0; j < NUM_PLANETS; j++) {
			char s1[20], s2[20];
			ToUpper(argv[i], s1);
			ToUpper(planets[j], s2);

			if (strcmp(s1, s2) == 0) {
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		}

		if (j == NUM_PLANETS) {
			printf("%s is not a planet\n", argv[i]);
		}
	}

	return 0;
}
