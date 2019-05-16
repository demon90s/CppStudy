/*
	Raw String Literal

	可以省去 escape 的字符序列。

	语法是：R"delim(...)delim"

	delim 的存在是为了在 ... 中也包含括号。 delim 可以省略掉。
 */

#include <cstdio>

int main()
{
	printf("%s", "\\\\n");
	putchar('\n');

	// 等价的操作
	printf("%s", R"(\\n)");
	putchar('\n');

	// 输出
	// Hello
	// World(by raw string)
	const char *hi = R"nc(Hello
World(by raw string))nc";
	printf("%s\n", hi);

	return 0;
}
