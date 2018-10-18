/*
 * 面试题2：实现 Singleton 模式
 *
 * 题目：设计一个类，我们只能生成该类的一个实例。
 */

class System
{
public:
	static System& Instance()
	{
		static System inst;
		return inst;
	}

private:
	System() {}
	~System() {}
};

int main()
{
	// 在程序开始前，就实例化
	System::Instance();

	return 0;
}
