/*
	swap(a,b)
	交换a,b

	内部，数值被 moved 或者被 move assigned 。
	要求参数类型提供了 move 或者 copy 语义。

	C++11还提供了交换相同类型数组的操作。

	swap() 的最大优势是可以特化自己的版本，从而提高效率。
*/

#include <cstring>
#include <utility>
#include <iostream>

void Test1()
{
	int x = 42, y = 100;

	std::swap(x, y);

	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}

void Test2()
{
	auto print_array = [](int *arr, int len) {
		for (int i = 0; i < len; ++i) {
			std::cout << " " << arr[i];
		}
		std::cout << std::endl;
	};

	int arr[] = {1, 2, 3, 4};
	int brr[] = {6, 7, 8, 9};

	std::cout << "before swap:\n";
	std::cout << "arr:"; print_array(arr, 4);
	std::cout << "brr:"; print_array(brr, 4);

	std::swap(arr, brr);

	std::cout << "after swap:\n";
	std::cout << "arr:"; print_array(arr, 4);
	std::cout << "brr:"; print_array(brr, 4);
}

//------------------------------------------------------------

class Foo {
public:
	Foo(int i) : elems(new int(i)) {}
	~Foo() { delete elems; }
	// 忽略拷贝构造和赋值操作
	
	const int* GetElems() const { return elems; }
	
	// implemetation of swap()
	void swap(Foo &f) {
		std::swap(elems, f.elems);
	}

private:
	int *elems;
};

// overloaded global swap() for this type
inline void swap(Foo &f1, Foo &f2) noexcept(noexcept(f1.swap(f2)))
{
	std::cout << "swapping...\n";
	f1.swap(f2);
}

std::ostream& operator<<(std::ostream &os, const Foo &foo)
{
	os << *foo.GetElems();
	return os;
}

//----------------------------------------------------------

void Test3()
{
	Foo f1(42), f2(100);
	
	std::cout << "before swap:\n";
	std::cout << "f1: " << f1 << std::endl;
	std::cout << "f2: " << f2 << std::endl;

	swap(f1, f2);

	std::cout << "after swap:\n";
	std::cout << "f1: " << f1 << std::endl;
	std::cout << "f2: " << f2 << std::endl;
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}
