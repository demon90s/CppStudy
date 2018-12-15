// 练习14.37：编写一个类令其检查两个值是否相等。使用该对象及标准库算法编写程序，
// 令其替换某个序列中具有给定值的所有实例。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Equal
{
public:
	Equal(int cmp) : m_cmp(cmp) {}
	bool operator()(int t) const { return m_cmp == t; }

private:
	int m_cmp;
};

int main()
{
	vector<int> vec = {1, 2, 3, 2, 2, 5};

	//replace(vec.begin(), vec.end(), 2, 20);
	
	replace_if(vec.begin(), vec.end(), Equal(2), 20);

	for_each(vec.cbegin(), vec.cend(), [](int i) { cout << i << " "; });

	return 0;
}
