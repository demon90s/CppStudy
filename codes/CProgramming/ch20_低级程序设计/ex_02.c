/*
    请说出如何“切换”一个位（从0改为1或从1改为0）.通过编写一条语句切换变量i的第4位来说明
    这种方法。
*/

/*
    对该位取反。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintFlag(int _flag)
{
	char buf[65] = { 0 };

	int flag = 0;
	memcpy(&flag, &_flag, sizeof(_flag));

	itoa(flag, buf, 2);

	printf("flag: %s\n", buf);
}

int main(int argc, char const *argv[])
{
    int i = 0xFF; /* 11111111 */
    
    PrintFlag(i);

    i &= ~(1 << 3);
    PrintFlag(i);

    i |= (1 << 3);
    PrintFlag(i);

    return 0;
}
