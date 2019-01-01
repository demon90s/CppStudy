/*
 * 练习5.11：修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
 */

// ./exercise_5_11 < data/vowels.txt

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
	char ch = 0;

	while (cin >> std::noskipws >> ch) { // std::noskipws表示不忽略空白字符
		switch (ch) {
			case ' ':
				++spaceCnt;
				break;

			case '\t':
				++tabCnt;
				break;

			case '\n':
				++newlineCnt;
				break;

			case 'a':
			case 'A':
				++aCnt;
				break;

			case 'e':
			case 'E':
				++eCnt;
				break;

			case 'i':
			case 'I':
				++iCnt;
				break;

			case 'o':
			case 'O':
				++oCnt;
				break;

			case 'u':
			case 'U':
				++uCnt;
				break;
		}
	}

	cout << "Number of space: " << spaceCnt << endl;
	cout << "Number of tab: " << tabCnt << endl;
	cout << "Number of newline: " << newlineCnt << endl;
	cout << "Number of vowel a: " << aCnt << endl;
	cout << "Number of vowel e: " << eCnt << endl;
	cout << "Number of vowel i: " << iCnt << endl;
	cout << "Number of vowel o: " << oCnt << endl;
	cout << "Number of vowel u: " << uCnt << endl;

	return 0;
}
