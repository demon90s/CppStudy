// 练习18.28：已知存在如下的继承体系，在VMI类的内部哪些继承而来的成员无须前缀
// 限定符就能直接访问？哪些必须有限定符才能访问？说明你的原因。

struct Base {
	void bar(int);
protected:
	int ival;
};

struct Derived1 : virtual public Base {
	void bar(char);
	void foo(char);
protected:
	char cval;
};

struct Derived2 : virtual public Base {
	void foo(int);
protected:
	int ival;
	char cval;
};

class VMI : public Derived1, public Derived2 {
public:
	void test()
	{
		// ival可以直接访问，Derived2的优先级更高
		(void)ival;

		// cval不能直接访问，会产生二义性
		//(void)cval;

		// foo不能直接访问，会产生二义性
		//foo(42);
		
		// bar可以直接访问，Derived1的优先级更高
		bar(42);
	}
};

//---------------------------------------------------------

int main()
{
	return 0;
}
