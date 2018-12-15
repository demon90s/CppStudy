/*
 * 练习5.9：编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。
 */

/*
 * $ ./exercise_5_09 < data/vowels.txt
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int aCnt = 0;
	int eCnt = 0;
	int iCnt = 0;
	int oCnt = 0;
	int uCnt = 0;
	char ch = '\0';

	while (cin >> ch) {
		if (ch == 'a')
			++aCnt;
		else if (ch == 'e')
			++eCnt;
		else if (ch == 'i')
			++iCnt;
		else if (ch == 'o')
			++oCnt;
		else if (ch == 'u')
			++uCnt;
	}

	cout << "Number of vowel a: " << aCnt << endl;
	cout << "Number of vowel e: " << eCnt << endl;
	cout << "Number of vowel i: " << iCnt << endl;
	cout << "Number of vowel o: " << oCnt << endl;
	cout << "Number of vowel u: " << uCnt << endl;

	return 0;
}
