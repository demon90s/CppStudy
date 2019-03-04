#include <string>
#include <iostream>

int main()
{
	/*
	 * s.insert(pos, args)
	 *
	 * 在 pos 之前插入 args 指定的字符。 pos 可以是一个下标或一个迭代器。
	 * 接受下标的版本返回一个指向 s 的引用；接受迭代器的版本返回执行第一个插入字符的迭代器。
	 */

	{
		std::string s = "Hello world";
		s.insert(s.size(), 5, '!');	// 在s末尾插入5个感叹号

		std::cout << s << std::endl;
	}

	{
		const char *cp = "Stately, plump back";
		std::string s = "Hey";
		s.insert(s.size(), cp + 7); // "Hey, plump back"

		std::cout << s << std::endl;
	}

	{
		std::string s = "some string", s2 = "some other string";
		s.insert(0, s2); // 在s中位置0之前插入s2的拷贝

		std::cout << s << std::endl;
	}

	{
		std::string s = "some string", s2 = "some other string";
		s.insert(0, s2, 0, s2.size()); // 在s[0]之前插入s2中s2[0]开始的s2.size()个字符

		std::cout << s << std::endl;
	}

	return 0;
}
