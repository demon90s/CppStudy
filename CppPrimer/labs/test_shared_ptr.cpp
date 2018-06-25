#include <iostream>
#include <memory>

using namespace std;

int main()
{
	auto p1 = make_shared<int>(10);
	auto p2(p1);
	auto p3(p2);

	cout << "p1 use_count: " << p1.use_count() << endl;
	cout << "p2 use_count: " << p2.use_count() << endl;
	cout << "p3 use_count: " << p3.use_count() << endl;

	return 0;
}
