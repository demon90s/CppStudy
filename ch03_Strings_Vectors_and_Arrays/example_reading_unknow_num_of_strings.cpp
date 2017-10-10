/*
 * ./example_reading_unknow_num_of_strings < example_reading_unknow_num_of_strings.cpp
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string word;
	while (cin >> word)
		cout << word << endl;

	return 0;
}
