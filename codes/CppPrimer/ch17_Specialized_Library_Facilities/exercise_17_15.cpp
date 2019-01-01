// 练习17.15：编写程序，使用模式查找违反“i在e之前，除非在c之后”规则的单词。
// 你的程序应该提示用户输入一个单词，然后指出此单词是否符合要求。用一些违反
// 和未违反的单词测试你的程序。

#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool InValid(const string &word)
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	// 练习17.16
	//regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	//regex r("[^c]ei");
	
	const static regex r(pattern);
	smatch results;

	return regex_search(word, results, r);
}

int main()
{
	string word;
	do
	{
		cout << "enter a word to test: ";
		if (!(cin >> word))
		{
			break;
		}

		if (InValid(word))
		{
			cout << "InValid word" << endl;
		}
		else
		{
			cout << "Valid word" << endl;
		}

	} while (true);

	return 0;
}
