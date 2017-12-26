// 练习10.33：编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入
// 文件保存的应该是整数。使用istream_iterator读取输入文件。使用ostream_iterator
// 将奇数写入第一个输出文件，每个值之后都跟一个空格。将偶数写入第二个输出文件，
// 每个值都独占一行。

// ./exercise_10_33 ../data/numbers.txt out1 out2

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 4) {
		cout << "usage: ./exercise_10_33 in_file out_file1 out_file2";
		return 1;
	}

	ifstream in(argv[1]);
	ofstream out1(argv[2]), out2(argv[3]);
	if (!in || !out1 || !out2) {
		cout << "open file fail" << endl;
		return 1;
	}

	istream_iterator<int> in_iter(in), in_eof;
	ostream_iterator<int> out1_iter(out1, " "), out2_iter(out2, " ");
	vector<int> v(in_iter, in_eof);
	copy_if(v.begin(), v.end(), out1_iter, [](int i) { return i % 2 != 0; });
	copy_if(v.begin(), v.end(), out2_iter, [](int i) { return i % 2 == 0; });

	return 0;
}
