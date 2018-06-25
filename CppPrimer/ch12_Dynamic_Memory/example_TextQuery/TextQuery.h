#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include "../../ch16_Templates_and_GenericProgramming/example_member_template/DebugDelete.h" // 练习16.22（p597）

class QueryResult; // 为了定义函数query的返回类型，这个定义是必须的
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file; // 输入文件
	//std::shared_ptr<std::vector<std::string>, DebugDelete> file; // 输入文件
	
	// 每个单词到它所在的行号的集合的映射
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif // TEXT_QUERY_H
