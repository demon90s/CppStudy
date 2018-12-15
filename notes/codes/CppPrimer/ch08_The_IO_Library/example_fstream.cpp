// example: 使用fstream代替iostream&读取Sales_data（p284）

// ./example_fstream ../ch07_Classes/data/book_sales /tmp/tmp_out.txt

#include <iostream>
#include <fstream>
#include "../ch07_Classes/example_Sales_data/Sales_data.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 2) return 1;

	ifstream in(argv[1]); 	// 打开销售记录文件
	ofstream out(argv[2]);	// 打开输出文件

	Sales_data total;	// 保存下一条交易记录的变量
	// 读入第一条交易记录，并确保有数据可以处理
	if (read(in, total)) {
		Sales_data trans;	// 保存和的变量
		// 读入并处理剩余交易记录
		while (read(in, trans)) {
			// 如果我们仍在处理相同的书
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(out, total) << endl;	// 输出结果
				total = trans;		// 处理下一本书
			}
		}
		print(out, total) << endl;	// 输出最后一条交易
	}
	else {
		cerr << "No data?!" << endl;
	}

	return 0;
}
