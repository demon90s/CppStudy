/*
 * 练习1.20：在网站http://www.informit.com/title/032174113上，第一章的代码目录中包含了头文件Sales_item.h。将它拷贝到你自己的工作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。
 */

/*
 * $ ./exercise_1_20 < data/book_sales
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item book;

	while (std::cin >> book)
		std::cout << book << std::endl;

	return 0;
}
