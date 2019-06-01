// 练习9.40：如果上一题中的程序读入了256个词，在resize之后容器的capacity可能是多少？
// 如果读入了512个，1000个或1048个词呢？

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> svec;
	svec.reserve(1024);
	string word;

	/*
	while (cin >> word)
		svec.push_back(word);
	*/

	// 换一种模拟方法
	static constexpr int count = 1000;
	for (int i = 0; i < count; ++i) {
		svec.push_back("hello");
	}

	svec.resize(svec.size() + svec.size()/2);
	cout << "capacity: " << svec.capacity() << endl;

	// 256: 1024
	// 512: 1024
	// 1000: 2048 GCC上是2000
	// 1048: 2048

	return 0;
}
