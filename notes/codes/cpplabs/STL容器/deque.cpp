#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

// deque 运用实例
void test()
{
	// create empty deque of strings
	std::deque<std::string> coll;

	// insert several elements
	coll.assign(3, std::string("string"));
	coll.push_back("last string");
	coll.push_front("first string");

	// print elements separated by newlines
	std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

	// remove first and last element
	coll.pop_front();
	coll.pop_back();
	
	// insert "another" into every element but the first
	for (unsigned i = 1; i < coll.size(); ++i) {
		coll[i] = "another " + coll[i];
	}

	// change size to four elements
	coll.resize(4, "resized string");

	// print elements separated by newlines
	std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main()
{
	test();
	return 0;
}
