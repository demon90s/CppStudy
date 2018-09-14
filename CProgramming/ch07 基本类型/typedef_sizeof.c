/* 测试typedef和sizeof */

#include <stdio.h>

typedef char Name[32];

int main()
{
	Name name;

	printf("sizeof name: %lu\n", sizeof(name));

	return 0;
}
