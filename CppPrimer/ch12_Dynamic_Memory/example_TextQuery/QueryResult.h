#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory>

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(std::string s,
				std::shared_ptr<std::set<line_no>> p,
				std::shared_ptr<std::vector<std::string>> f):
		sought(s), lines(p), file(f) {}

	std::set<line_no>::iterator begin() { return lines->begin(); }
	std::set<line_no>::iterator end()   { return lines->end(); }

	std::shared_ptr<std::vector<std::string>> get_file() const { return file; }

private:
	std::string sought;	// 查询单词
	std::shared_ptr<std::set<line_no>> lines;	// 出现的行号
	std::shared_ptr<std::vector<std::string>> file;	// 输入文件
};

extern std::ostream& print(std::ostream&, const QueryResult&);

#endif // QUERY_RESULT_H
