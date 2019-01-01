// 练习17.26：重写你的电话号码程序，使之对多于一个电话号码的人只输出第二个和后续电话号码。

// ./exercise_17_26 < ../data/person_numbers.txt

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);	// 寻找模式所用的regex对象

	smatch result;
	string s;

	vector<vector<string>> person_numbers;

	while (getline(cin, s))
	{
		vector<string> numbers;

		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			numbers.push_back(it->str()); 
		}

		person_numbers.push_back(numbers);
	}

	for (const auto &numbers : person_numbers)
	{
		if (numbers.empty()) continue;

		if (numbers.size() > 1)
		{
			for (size_t i = 1; i < numbers.size(); ++i)
			{
				cout << numbers[i] << " ";
			}
		}
		else
		{
			cout << numbers[0]; 
		}

		cout << endl;
	}

	return 0;
}
