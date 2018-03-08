#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	istringstream iss("abc");
	char c;
	iss >> c;

	cout << c << endl;

	iss >> c;
	cout << c << endl;

	return 0;
}
