// example: ostream_iterator操作（p361）

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<int> vec{1, 2, 3, 4};
	ostream_iterator<int> out_iter(cout, " ");
	for (auto i : vec)
		*out_iter++ = i;
	cout << endl;

	return 0;
}
