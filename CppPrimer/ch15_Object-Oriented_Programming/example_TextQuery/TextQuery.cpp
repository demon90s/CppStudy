#include <sstream>
#include <string>

#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

// 把word里面不属于字母的内容剔除掉
inline void FixWord(string &word)
{
	static string s;
	s.clear();
	for (auto c : word)	{
		if (isalpha(c))
			s.push_back(c);
	}
	word = s;
}

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
	string text;
	while (getline(is, text)) {		// 对文件中的每一行
		file->push_back(text);		// 保存此行文本
		int n = file->size() - 1;	// 当前行号
		istringstream line(text);	// 将行文本分解为单词
		string word;
		while (line >> word) {		// 对行中每个单词
			FixWord(word);
			// 如果单词不在wm中，以之为下标在wm中添加一项
			auto &lines = wm[word];	// lines是一个shared_ptr
			if (!lines)				// 在我们第一次遇到这个单词时，此指针为空
				lines.reset(new set<line_no>);	// 分配一个新的set
			lines->insert(n);		// 将此行号插入set中
		}
	}
}

QueryResult
TextQuery::query(const string &sought) const
{
	// 如果未找到sought，我们将返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	// 使用find而不是下标运算符来查找单词，避免将单词添加到wm中！
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);	// 未找到
	else
		return QueryResult(sought, loc->second, file);
}
