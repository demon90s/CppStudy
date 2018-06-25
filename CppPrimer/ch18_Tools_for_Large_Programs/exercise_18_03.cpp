// 练习18.3：要想让上面的代码在发生异常时能正常工作，有两种解决方案。请描述这两种
// 方法并实现它们。

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

void exercise1(int *b, int *e)
{
	class IntList
	{
	public:
		IntList(size_t sz) : lst(new int[sz]()) {}
		~IntList() { cout << "~IntList()" << endl; delete [] lst; }

	private:
		int *lst = nullptr;
	};

	vector<int> v(b, e);
	IntList il(v.size()); // 改成用类来管理
	ifstream in("ints");

	throw runtime_error("test exception");
}

void exercise2(int *b, int *e)
{
	vector<int> v(b, e);
	unique_ptr<int[]> up(new int[v.size()]()); // 使用智能指针管理
	ifstream in("ints");

	throw runtime_error("test exception");
}

int main()
{
	int arr[] = {1, 2, 3};
	exercise1(begin(arr), end(arr));
	//exercise2(begin(arr), end(arr));

	return 0;
}
