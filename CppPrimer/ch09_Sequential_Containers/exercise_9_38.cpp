// 练习9.38：编写程序，探究在你的标准库实现中，vector是如何增长的。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	// GCC，capacity需要扩张时，每次都翻倍增长
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		cout << "vector size: " << v.size()
		     << " capacity: " << v.capacity() << endl;
	}

	return 0;
}
