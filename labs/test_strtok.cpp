// test: 测试strtok
// 参加：http://zh.cppreference.com/w/cpp/string/byte/strtok

/*
 * 注意点：
 * 1. strtok修改了参数input，它写入'\0'替换delim
 * 2. 每次对strtok调用都会修改静态对象，它不是线程安全的。且strtok未处理完一个字符串时，不能调用它处理另一个字符串。
 */

#include <cstring>
#include <iostream>

int main()
{
	char input[100] = "A bird came down the walk";
	char *token = std::strtok(input, " ");
	while (token != NULL) {
		std::cout << token << "\n";
		token = std::strtok(NULL, " ");
	}

	return 0;
}
