// 专门为练习15.37定义的文件

#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>

#include "QueryResult.h"
#include "TextQuery.h"

static constexpr bool open_debug = true;
inline void PrintDebug(const char *msg)
{
	if (open_debug)
		std::cout << "[Debug] " << msg << "\n";
}

static QueryResult invalid_qr("", 0, 0);

// 这是一个抽象基类，具体的查询类型从中派生，所有成员都是private的
class Query_base {
	friend class Query;
	friend class NotQuery;
	friend class AndQuery;
	friend class OrQuery;
	friend class BinaryQuery;

protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;

private:
	// eval返回与当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;

	// rep是表示查询的一个string
	virtual std::string rep() const = 0;
};

class WordQuery : public Query_base {
	friend class Query;		// Query使用WordQuery构造函数

	WordQuery(const std::string &s) : query_word(s)
	{ PrintDebug("WordQuery::WordQuery(const std::string &s)"); }
	
	// 具体的类：WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t) const override
	{ return t.query(query_word); }

	std::string rep() const override
	{ 
		PrintDebug("WordQuery::rep");
		return query_word; 
	}
	std::string query_word;	// 要查找的单词
};

// 这是一个管理Query_base继承体系的接口类
class Query {
	// 这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

	friend class NotQuery;
	friend class AndQuery;
	friend class OrQuery;
	friend class BinaryQuery;

public:
	Query(const std::string &s) : q(new WordQuery(s))	// 构建一个新的WordQuery
	{ PrintDebug("Query::Query(const std::string &s)"); }

	// 接口函数：调用对应的Query_base操作
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const
	{ 
		PrintDebug("Query::rep");
		return q->rep(); 
	}

private:
	Query(std::shared_ptr<Query_base> query) : q(query)
	{ PrintDebug("Query::Query(std::shared_ptr<Query_base> query)"); }

	std::shared_ptr<Query_base> q;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
	// Query::rep通过它的Query_base指针对rep()进行了虚调用
	return os << query.rep();
}

class NotQuery : public Query_base {
	friend Query operator~(const Query&);
	
	NotQuery(const Query &q) : query(q.q)
	{ PrintDebug("NotQuery::NotQuery(const Query &q)"); }

	// 具体的类：NotQuery将定义所有继承而来的纯虚函数
	std::string rep() const
	{ 
		PrintDebug("NotQuery::rep");
		return "~" + query->rep() + ")"; 
	}

	QueryResult eval(const TextQuery&) const;
	std::shared_ptr<Query_base> query;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l.q), rhs(r.q), opSym(s)
	{ PrintDebug("BinaryQuery::BinaryQuery(const Query &l, const Query &r, std::string s)"); }

	// 抽象类：BinaryQuery不定义eval
	std::string rep() const
	{
		PrintDebug("BinaryQuery::rep");
		return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")";
	}

	std::shared_ptr<Query_base> lhs, rhs;		// 左侧和右侧的运算对象
	std::string opSym;	// 运算符的名字
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);

	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&")
	{ PrintDebug("AndQuery::AndQuery(const Query &left, const Query &right)"); }

	// 具体的类：AndQuery继承了rep并且定义了其他纯虚函数
	QueryResult eval(const TextQuery&) const { return invalid_qr; }
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
};

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);

	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|")
	{ PrintDebug("OrQuery::OrQuery(const Query &left, const Query &right)"); }

	QueryResult eval(const TextQuery&) const { return invalid_qr; }
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif
