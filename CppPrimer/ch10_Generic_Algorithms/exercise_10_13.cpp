// 练习10.13：标准库定义了名为partition的算法，它接受一个谓词，对容器内容进行
// 划分，使得谓词为true的值会排在容器的前半部分，而使谓词为false的值会排在后
// 半部分。算法返回一个迭代器，指向最后一个谓词为true的元素之后的位置。编写函数，
// 接受一个string，返回一个bool值，指出string是否有5个或更多字符。使用此函数
// 划分words。打印出长度大于等于5的元素。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool charMoreThan(const string &str)
{
	return str.size() >= 5;
}

int main()
{
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

	auto end = partition(words.begin(), words.end(), charMoreThan);

	for (auto beg = words.begin(); beg != end; ++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
	

	return 0;
}
