/*
 * 使用 typedef 产生名为 Int8 、 Int16 和 Int32 的类型。定义这些类型以便它们可以在你的机器上分
 * 别表示8位、16位和32位的整数。
 */

/*
 * PS，我的机器架构是：x86_64
 */

#include <stdio.h>

typedef char Int8;
typedef short Int16;
typedef int Int32;

int main()
{
	printf("bits of Int8: %lu\n", 8 * sizeof(Int8));
	printf("bits of Int16: %lu\n", 8 * sizeof(Int16));
	printf("bits of Int32: %lu\n", 8 * sizeof(Int32));

	return 0;
}
