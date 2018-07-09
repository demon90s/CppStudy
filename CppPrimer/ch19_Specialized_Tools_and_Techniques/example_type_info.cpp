// example: type_info类（p735）

#include <typeinfo>
#include <iostream>

int main()
{
	int arr[10];
	int i_val;
	double d_val;

	std::cout << typeid(arr).name() << "\n"
		<< typeid(i_val).name() << "\n"
		<< typeid(d_val).name() << std::endl;

	return 0;
}
