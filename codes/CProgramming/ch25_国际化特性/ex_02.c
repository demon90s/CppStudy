/*
 * 编写一个程序，用来测试你用的编译器的""（本地）地区是否和"C"地区一样。
 */

/*
 * 不一样，""是 en_US.utf8 ，而 "C" 是 C 。
 */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void test2()
{
	printf("'': %s\n", setlocale(LC_ALL, ""));
	printf("'C': %s\n", setlocale(LC_ALL, "C"));

}

int main()
{
	test2();

	return 0;
}
