// 练习14.35：编写一个类似于PrintString的类，令其从istream中读取一行输入，
// 然后返回一个表示我们所读内容的string，如果读取失败，返回空string。

#include <iostream>
#include <string>

using namespace std;

class ReadString
{
public:
	ReadString(istream &is) : m_is(is) {}
	string operator()() const
	{
		string line;
		if (getline(m_is, line))
			return line;
		return "";
	}

private:
	istream &m_is;
};

int main()
{
	ReadString reader(cin);
	cout << reader() << endl;

	return 0;
}
