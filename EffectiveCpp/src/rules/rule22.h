// 条款22：将成员变量声明为 private

#include <iostream>

extern void Rule22();

namespace rule22
{
	// 若成员变量是 public 的
	class Foo
	{
	public:
		Foo() : id(0) {}
		int GetID() const { return id; }

		int id;
	};

	// 一致性问题，如果成员变量是 public ，那么就有多种访问办法
	inline void func1()
	{
		Foo f;
		std::cout << f.id << std::endl;
		std::cout << f.GetID() << std::endl;
	}

	// 无法得到精确的控制、没有封装性
	inline void func2()
	{
		Foo f;
		f.id = 10; // 若将来 id 被移除了，客户码也会被破坏
	}
}