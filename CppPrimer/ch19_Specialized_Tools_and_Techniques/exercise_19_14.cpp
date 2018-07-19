//练习19.14：下面的代码合法吗？如果合法，代码的含义是什么？
//如果不合法，解释原因。


/*
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
*/

// 不合法，函数类型不一致。

class Screen
{
public:
	char get_cursor() const { return 0; }
	char get(unsigned w, unsigned h) const { return 0; }
};

int main()
{
	auto pmf = &Screen::get_cursor;
	//pmf = &Screen::get;
	
	(void)pmf;

	return 0;
}
