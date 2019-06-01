// 练习17.3：重写12.3节（第430页）中的TextQuery程序，使用tuple代替QueryResult类。
// 你认为哪种设计更好？为什么？

// 使用tuple可以降低代码量，但是对于扩展功能不友好。所以我更愿意使用QueryResult。

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <sstream>
#include <tuple>

typedef std::tuple<std::string, std::shared_ptr<std::set<size_t>>, std::shared_ptr<std::vector<std::string>>> QueryResult;

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file; // 输入文件
	
	// 每个单词到它所在的行号的集合的映射
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is): file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text)) {		// 对文件中的每一行
		file->push_back(text);		// 保存此行文本
		int n = file->size() - 1;	// 当前行号
		std::istringstream line(text);	// 将行文本分解为单词
		std::string word;
		while (line >> word) {		// 对行中每个单词
			// 如果单词不在wm中，以之为下标在wm中添加一项
			auto &lines = wm[word];	// lines是一个shared_ptr
			if (!lines)				// 在我们第一次遇到这个单词时，此指针为空
				lines.reset(new std::set<line_no>);	// 分配一个新的set
			lines->insert(n);		// 将此行号插入set中
		}
	}
}

QueryResult
TextQuery::query(const std::string &sought) const
{
	// 如果未找到sought，我们将返回一个指向此set的指针
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

	// 使用find而不是下标运算符来查找单词，避免将单词添加到wm中！
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);	// 未找到
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	// 如果找到了单词，打印出现次数和所有出现的位置
	os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " time(s)" << std::endl;

	// 打印单词出现的每一行
	for (auto num : *std::get<1>(qr)) // 对set中每个单词
		// 避免行号从0开始给用户带来的困惑
		os << "\t(line " << num + 1 << ") "
			<< *(std::get<2>(qr)->begin() + num) << std::endl;
	return os;
}

void runQueries(std::ifstream &infile)
{
	// infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile); // 保存文件并建立查询map

	// 与用户交互，提示用户输入要查询的单词，完成查询并打印结果
	while (true)
	{
		std::cout << "Enter word to look for, or q to quit: ";
		std::string s;
		// 若遇到了文件尾或用户输入了q时循环终止
		if (!(std::cin >> s) || s == "q") break;

		// 指向查询并打印结果
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	std::ifstream infile("../data/some_words.txt");
	if (!infile)
	{
		std::cout << "Cant open file" << std::endl;
		return 1;
	}

	runQueries(infile);

	return 0;
}
