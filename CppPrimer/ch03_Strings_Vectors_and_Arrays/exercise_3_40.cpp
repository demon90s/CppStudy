/*
 * 练习3.40：编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前两个数组连接后的结果。使用strcpy和strcat把前两个数组的内容拷贝到第三个数组中。
 */

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
	char str1[] = "Hello";
	char str2[] = "World";
	
	constexpr size_t sz = sizeof(str1) + sizeof(str2) - 1;
	char str3[sz] = {0};

	strcpy(str3, str1);
	strcat(str3, str2);

	cout << str3 << endl;

	return 0;
}
