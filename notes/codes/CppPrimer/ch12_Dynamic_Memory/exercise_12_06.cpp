// 练习12.6：编写函数，返回一个动态分配的int的vector。将此vector传递给
// 另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。再将
// vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

#include <iostream>
#include <vector>

using namespace std;

vector<int>* create_vec()
{
	return new vector<int>();
}

void read_for_vec(vector<int> *vec)
{
	int n = 0;
	while (cin >> n)
	{
		vec->push_back(n);
	}
}

void print_vec(vector<int> *vec)
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

	delete vec;

	return 0;
}
