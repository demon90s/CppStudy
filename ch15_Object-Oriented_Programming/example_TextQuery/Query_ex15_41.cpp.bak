#include "Query.h"
#include <algorithm>

// 返回运算对象查询结果set的并集
QueryResult
OrQuery::eval(const TextQuery &text) const
{
	// 通过Query成员lhs和rhs进行虚调用
	// 调用eval返回每个运算对象的QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);

	// 将左侧运算对象的行号拷贝到结果set中
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());

	// 插入右侧运算对象所得的行号
	ret_lines->insert(right.begin(), right.end());

	// 返回一个新的QueryResult，它表示lhs和rhs的并集
	return QueryResult(rep(), ret_lines, left.get_file());
}

// 返回运算对象查询结果set的交集
QueryResult
AndQuery::eval(const TextQuery &text) const
{
	// 通过Query运算对象进行的虚调用，以获得运算对象的查询结果set
	auto left = lhs.eval(text), right = rhs.eval(text);

	// 保存left和right交集的set
	auto ret_lines = std::make_shared<std::set<line_no>>();

	// 将两个范围的交集写入一个目的迭代器中
	// 本次调用的目的迭代器向ret添加元素
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}

// 返回运算对象的结果set中不存在的行
QueryResult
NotQuery::eval(const TextQuery &text) const
{
	// 通过Query运算对象对eval进行虚调用
	auto result = query.eval(text);

	// 开始时结果为空
	auto ret_lines = std::make_shared<std::set<line_no>>();

	// 我们必须在运算对象出现的所有行中进行迭代
	auto beg = result.begin(), end = result.end();

	// 对于输入文件的每一行，如果该行不在result当中，则将其添加到ret_lines
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		// 如果我们还没有处理完result的所有行
		// 检查当前行是否存在
		if (beg == end || *beg != n)
			ret_lines->insert(n);	// 如果不在result中，添加这一行
		else if (beg != end)
			++beg;	// 否则继续获取result的下一行（如果有的话）
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}
