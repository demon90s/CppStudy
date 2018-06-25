/*
 * 练习5.12：修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff、fl和fi。
 */

// ./exercise_5_12 < data/vowels.txt

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch = 0;

	char prech = 0;	// 上一次读取的字符
	int ffCnt = 0, flCnt = 0, fiCnt = 0;

	while (cin >> std::noskipws >> ch) {
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
				if (prech == 'f') ++fiCnt;
				break;

			case 'o':
			case 'O':
				++oCnt;
				break;

			case 'u':
			case 'U':
				++uCnt;
				break;

			case 'l':
				if (prech == 'f') ++flCnt;
				break;

			case 'f':
				if (prech == 'f') ++ffCnt;
		}

		prech = ch;
	}

	cout << "Number of vowel a: " << aCnt << endl;
	cout << "Number of vowel e: " << eCnt << endl;
	cout << "Number of vowel i: " << iCnt << endl;
	cout << "Number of vowel o: " << oCnt << endl;
	cout << "Number of vowel u: " << uCnt << endl;
	cout << "Number of vowel ff: " << ffCnt << endl;
	cout << "Number of vowel fl: " << flCnt << endl;
	cout << "Number of vowel fi: " << fiCnt << endl;

	return 0;
}
