#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory>

#include "StrVec.h"

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = size_t;
	QueryResult(std::string s,
				std::shared_ptr<std::set<line_no>> p,
				std::shared_ptr<StrVec> f):
		sought(s), lines(p), file(f) {}

	std::set<line_no>::iterator begin() { return lines->begin(); }
	std::set<line_no>::iterator end()   { return lines->end(); }

	std::shared_ptr<StrVec> get_file() const { return file; }

private:
	std::string sought;	// 查询单词
	std::shared_ptr<std::set<line_no>> lines;	// 出现的行号
	std::shared_ptr<StrVec> file;	// 输入文件
};

extern std::ostream& print(std::ostream&, const QueryResult&);

#endif // QUERY_RESULT_H
