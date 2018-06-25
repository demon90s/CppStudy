// 练习12.7：重做上一题，这次使用shared_ptr而不是内置指针。

// 练习12.6：编写函数，返回一个动态分配的int的vector。将此vector传递给
// 另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。再将
// vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> create_vec()
{
	return make_shared<vector<int>>();
}

void read_for_vec(shared_ptr<vector<int>> vec)
{
	int n = 0;
	while (cin >> n)
	{
		vec->push_back(n);
	}
}

void print_vec(shared_ptr<vector<int>> vec)
{
	for (auto i : *vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	auto vec = create_vec();
	read_for_vec(vec);
	print_vec(vec);

	return 0;
}
