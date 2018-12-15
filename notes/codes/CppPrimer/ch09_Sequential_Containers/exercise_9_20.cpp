// 编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有
// 元素拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。

#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define print_vec(vec)\
do {\
	cout << #vec << ": ";\
	for (auto i : vec)\
		cout << i << " ";\
	cout << endl;\
} while (0)

int main()
{
	list<int> ilst = {1, 2, 3, 4, 5, 6};
	deque<int> even_deq;
	deque<int> odd_deq;

	for (auto i : ilst) {
		if (0 == i % 2)
			even_deq.push_back(i);
		else
			odd_deq.push_back(i);
	}

	print_vec(even_deq);
	print_vec(odd_deq);

	return 0;
}
