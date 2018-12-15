/*
 * 练习5.10：我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以此类推。
 */

// ./exercise_5_10 < data/vowels.txt

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch = 0;

	while (cin >> ch) {
		switch (ch) {
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

	cout << "Number of vowel a: " << aCnt << endl;
	cout << "Number of vowel e: " << eCnt << endl;
	cout << "Number of vowel i: " << iCnt << endl;
	cout << "Number of vowel o: " << oCnt << endl;
	cout << "Number of vowel u: " << uCnt << endl;

	return 0;
}
