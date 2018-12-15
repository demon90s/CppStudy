// 练习12.26：用allocator重写第427页的程序。

#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
	size_t n = 4;
	size_t real_n = 0;

	allocator<string> alloc;
	auto const p = alloc.allocate(n);

	string s;
	string *q = p;
	while (cin >> s && q != p + n)
	{
		alloc.construct(q++, s);
		++real_n;
	}

	// print test
	{
		string *q = p;
		while (q != p + real_n)
			cout << *q++ << " ";
		cout << endl;
	}

	// destroy
	{
		string *q = p;
		while (q != p + real_n)
			alloc.destroy(q++);
	}

	alloc.deallocate(p, n);

	return 0;
}
