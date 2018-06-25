// example: 拷贝控制示例（p460）

#include <iostream>
#include "Folder.h"

using namespace std;

int main()
{
	Folder folder1("folder1");
	Folder folder2("folder2");
	Folder folder3("folder3");

	{
		Message msg1("Hi there");
		Message msg2("Hello world");
		Message msg3("Have a nice day");

		msg1.save(folder1);
		msg2.save(folder2);
		msg3.save(folder3);

		// Copy
		auto msg4(msg2);
		Message msg5;
		msg5 = msg2;

		folder1.print();
		folder2.print();
		folder3.print();

		cout << "\nmsg swap ..." << endl;
		swap(msg1, msg3);
		folder1.print();
		folder2.print();
		folder3.print();
	}

	cout << "\nmsg destruct ..." << endl;
	folder1.print();
	folder2.print();
	folder3.print();

	return 0;
}
