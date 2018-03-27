// example: Sales_data案例（自p228始）

// ./main < ../data/book_sales

#include <iostream>
#include "Sales_data.h"

using namespace std;

void test1()
{
	Sales_data total;	// 保存下一条交易记录的变量
	// 读入第一条交易记录，并确保有数据可以处理
	if (read(cin, total)) {
		Sales_data trans;	// 保存和的变量
		// 读入并处理剩余交易记录
		while (read(cin, trans)) {
			// 如果我们仍在处理相同的书
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;	// 输出结果
				total = trans;		// 处理下一本书
			}
		}
		print(cout, total) << endl;	// 输出最后一条交易
	}
	else {
		cerr << "No data?!" << endl;
	}
}

void test2()
{
	// 采用重载运算符的版本
	Sales_data total;
	if (cin >> total) {
		Sales_data trans;	// 保存和的变量
		// 读入并处理剩余交易记录
		while (cin >> trans) {
			// 如果我们仍在处理相同的书
			if (total.isbn() == trans.isbn()) {
				total += trans;
			}
			else {
				cout << total << endl;	// 输出结果
				total = trans;		// 处理下一本书
			}
		}
		cout << total << endl;	// 输出最后一条交易
	}
	else {
		cerr << "No data?!" << endl;
	}
	
}

int main()
{
	//test1();
	test2();

	return 0;
}
