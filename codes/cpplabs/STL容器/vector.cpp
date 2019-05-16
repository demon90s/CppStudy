#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

// 使用 vector 的案例
void test()
{
	// create empty vector for strings
	std::vector<std::string> sentence;

	// reserve memory for five elements to avoid reallocation
	sentence.reserve(5);

	// append some elements
	sentence.push_back("Hello,");
	sentence.insert(sentence.end(), {"how", "are", "you", "?"});

	// print elements separated with spaces
	copy(sentence.cbegin(), sentence.cend(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	// print "technical data"
	std::cout << " max_size(): " << sentence.max_size() << std::endl;
	std::cout << " size(): " << sentence.size() << std::endl;
	std::cout << " capacity(): " << sentence.capacity() << std::endl;

	// swap second and fourth element
	std::swap(sentence[1], sentence[3]);

	// insert element "always" before element "?"
	sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");

	// assign "!" to the last element
	sentence.back() = "!";

	// print elements separated with spaces
	copy(sentence.cbegin(), sentence.cend(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	// print some "technical data" again
	std::cout << " size(): " << sentence.size() << std::endl;
	std::cout << " capacity(): " << sentence.capacity() << std::endl;

	// delete last two elements
	sentence.pop_back();
	sentence.pop_back();

	// shrink capacity(since C++11)
	sentence.shrink_to_fit();

	// print some "technical data" again
	std::cout << " size(): " << sentence.size() << std::endl;
	std::cout << " capacity(): " << sentence.capacity() << std::endl;
}

// c++11 中顺序容器提供了 emplace 操作，它使用参数在容器管理的内存上直接构造出对象，而非像 push insert 那样拷贝一个对象
void test_emplace()
{
	std::vector<std::string> vec;

	vec.emplace_back("World");			// 功能对应 push_back
	vec.emplace(vec.begin(), "Hello");	// 功能对应 insert

	std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
}

// 测试增长机制
void test_increase()
{
	struct Foo {
		Foo() { std::cout << "Foo::Foo()\n"; }
		~Foo() { std::cout << "Foo::~Foo()\n"; }
		Foo(const Foo&) { std::cout << "Foo::Foo(const Foo&)\n"; }
	};

	Foo tmp;

	std::cout << "test begin--------------------\n";

	std::vector<Foo> foo_vec;
	foo_vec.reserve(1);

	foo_vec.push_back(tmp);

	std::cout << "will increase now...\n";
	foo_vec.push_back(tmp);			// 增长后, 会调用析构函数析构掉之前的元素

	std::cout << "test end  --------------------\n";
}

int main()
{
	//test();
	//test_emplace();

	test_increase();
	return 0;
}
