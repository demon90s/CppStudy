#include <iostream>
#include <memory>

using namespace std;

void test_use_count()
{
	auto p1 = make_shared<int>(10);
	auto p2(p1);
	auto p3(p2);

	cout << "p1 use_count: " << p1.use_count() << endl;
	cout << "p2 use_count: " << p2.use_count() << endl;
	cout << "p3 use_count: " << p3.use_count() << endl;
}

void test_deleter()
{
	auto deleter = [](int* p)
	{
		std::cout << "delete data: " << *p << std::endl;
		delete p;
	};

	std::shared_ptr<int> p(new int(42), deleter);
}

int main()
{
	//test_use_count();
	test_deleter();

	return 0;
}
