// test: 测试strtok
// 参考：http://zh.cppreference.com/w/cpp/string/byte/strtok

/*
 * char *strtok(char *input, const char *delim);
 * 
 * 寻找 input 中的 delim 。此函数使用的时候应该多次调用。
 * 
 * 如果 input 不为 NULL ，则表示首次调用。
 * 如果 input 为 NULL ，则表示后继调用，函数从先前调用中的剩下的位置开始。
 * 
 * 注意点：
 * 1. strtok修改了参数input，它写入'\0'替换delim
 * 2. 每次对strtok调用都会修改静态对象，它不是线程安全的。且strtok未处理完一个字符串时，不能调用它处理另一个字符串。
 */

#include <string.h>
#include <stdio.h>

int main()
{
	const char *delim = " ,!";
	char input[100] = "Look, A bird came down the walk";
	char *token = strtok(input, delim);
	while (token != NULL) {
		printf("get: %s\n", token);
		token = strtok(NULL, delim);
	}

	return 0;
}
