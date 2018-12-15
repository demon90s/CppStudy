// 练习13.17：分别编写前三题所描述的numbered和f， 验证你是否正确预测了输出结果。

#include <iostream>

using namespace std;

int gen_number()
{
	static int n = 0;
	return ++n;
}

namespace exercise1
{
	struct numbered
	{
		numbered() : mysn(gen_number()) {}
		int mysn;
	};

	void f(numbered s) { cout << s.mysn << endl; }
}

namespace exercise2
{
	struct numbered
	{
		numbered() : mysn(gen_number()) {}
		numbered(numbered &n) : mysn(gen_number()) {}
		int mysn;
	};

	void f(numbered s) { cout << s.mysn << endl; }
}

namespace exercise3
{
	struct numbered
	{
		numbered() : mysn(gen_number()) {}
		numbered(numbered &n) : mysn(gen_number()) {}
		int mysn;
	};

	void f(const numbered &s) { cout << s.mysn << endl; }
}

int main()
{
	// 练习13.14
	cout << "exercise 13.14:" << endl;
	{
		using namespace exercise1;
		numbered a, b = a, c = b;
		f(a); f(b); f(c); // 完全一样

		cout << "a: " << a.mysn << endl
			 << "b: " << b.mysn << endl
			 << "c: " << c.mysn << endl;
	}

	// 练习13.15
	cout << "exercise 13.15:" << endl;
	{
		using namespace exercise2;
		numbered a, b = a, c = b;
		f(a); f(b); f(c); // 都不一样，且有别于a,b,c

		cout << "a: " << a.mysn << endl
			 << "b: " << b.mysn << endl
			 << "c: " << c.mysn << endl;
	}

	// 练习13.16
	cout << "exercise 13.16:" << endl;
	{
		using namespace exercise3;
		numbered a, b = a, c = b;
		f(a); f(b); f(c); // 都不一样，且等于a,b,c

		cout << "a: " << a.mysn << endl
			 << "b: " << b.mysn << endl
			 << "c: " << c.mysn << endl;
	}

	return 0;
}
