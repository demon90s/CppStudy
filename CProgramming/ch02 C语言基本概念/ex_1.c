/*
 * 建立并运行由 Kernighan 和 Ritchie 编写的著名的”hello, world“程序：
 *
 * #include <stdio.h>
 *
 * main()
 * {
 *     printf("hello, world\n");
 * }
 *
 * 在编译时是否有警告信息？如果有，需要如何进行修改呢？
 */

/*
 * main 函数没有声明返回类型： warning: return type defaults to ‘int’ [-Wreturn-type]
 *
 * main 函数结尾没有 return 语句： warning: control reaches end of non-void function [-Wreturn-type]
 */

#include <stdio.h>

int main()
{
	printf("hello, world\n");

	return 0;
}
