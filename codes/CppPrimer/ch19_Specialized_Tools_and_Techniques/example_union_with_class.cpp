// example: 含有类类型成员的union（p750）

#include <iostream>
#include <string>
#include "../ch07_Classes/example_Sales_data/Sales_data.h"

using namespace std;

class Token {
	friend ostream& operator<<(ostream &os, Token &t);

public:
	// 因为union定义了一个string成员，所以Token必须定义拷贝控制成员
	Token() : tok(INT), ival(0) {}
	Token(const Token& t) : tok(t.tok) { copyUnion(t); }
	Token& operator=(const Token&);
	Token(Token &&t) : tok(t.tok) { moveCopyUnion(std::move(t)); }
	Token& operator=(Token&&);

	// 如果union含有一个string成员，则我们必须销毁它
	~Token()
	{ 
		if (tok == STR) sval.~string(); 
		else if(tok == SALES_DATA) sdval.~Sales_data();
	}

	// 下面的赋值运算符负责设置union的不同成员
	Token &operator=(const std::string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
	Token &operator=(const Sales_data&);
	
private:
	enum { INT, CHAR, DBL, STR, SALES_DATA } tok; // 判别式
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	}; // 每个Token对象含有一个该未命名union类型的未命名成员
	
	// 检查判别式，然后酌情拷贝union成员
	void copyUnion(const Token&);
	void moveCopyUnion(Token&&);
};

Token& Token::operator=(int i)
{
	if (tok == STR) sval.~string();
	else if (tok == SALES_DATA) sdval.~Sales_data();

	ival = i;
	tok = INT;
	return *this;
}

Token& Token::operator=(char c)
{
	if (tok == STR) sval.~string();
	else if (tok == SALES_DATA) sdval.~Sales_data();
	cval = c;
	tok = CHAR;
	return *this;
}

Token& Token::operator=(double d)
{
	if (tok == STR) sval.~string();
	else if (tok == SALES_DATA) sdval.~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
}

Token& Token::operator=(const std::string &s)
{
	if (tok == SALES_DATA) sdval.~Sales_data();

	if (tok == STR) sval = s;  // 如果当前存储的是string，则直接赋值
	else
		new (&sval) string(s);   // 否则需要先构造一个string
	tok = STR;
	return *this;
}

Token& Token::operator=(const Sales_data &sd)
{
	if (tok == STR) sval.~string();

	if (tok == SALES_DATA) sdval = sd;
	else
		new (&sdval) Sales_data(sd);

	tok = SALES_DATA;
	return *this;
}

void Token::copyUnion(const Token &t)
{
	switch (t.tok)
	{
	case INT: ival = t.ival;break;
	case CHAR: cval = t.cval;break;
	case DBL: dval = t.dval;break;
	case STR: new (&sval) string(t.sval);break;
	case SALES_DATA: new (&sdval) Sales_data(t.sdval);break;
	}
}

void Token::moveCopyUnion(Token &&t)
{
	switch (t.tok)
	{
	case INT: ival = t.ival;break;
	case CHAR: cval = t.cval;break;
	case DBL: dval = t.dval;break;
	case STR: new (&sval) string(std::move(t.sval));break;
	case SALES_DATA: new (&sdval) Sales_data(std::move(t.sdval));break;
	}
}

Token& Token::operator=(const Token &t)
{
	// 如果此对象是STR而t不是，则必须释放原来的string
	if (tok == STR && t.tok != STR) sval.~string();
	if (tok == SALES_DATA && t.tok != SALES_DATA) sdval.~Sales_data();

	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else if(tok == SALES_DATA && t.tok == SALES_DATA)
		sdval = t.sdval;
	else
		copyUnion(t);

	tok = t.tok;
	return *this;
}

Token& Token::operator=(Token &&t)
{
	// 如果此对象是STR而t不是，则必须释放原来的string
	if (tok == STR && t.tok != STR) sval.~string();
	if (tok == SALES_DATA && t.tok != SALES_DATA) sdval.~Sales_data();

	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else if(tok == SALES_DATA && t.tok == SALES_DATA)
		sdval = t.sdval;
	else
		moveCopyUnion(std::move(t));

	tok = t.tok;
	return *this;
}

ostream& operator<<(ostream &os, Token &t)
{
	switch (t.tok)
	{
	case Token::INT: os << t.ival;break;
	case Token::CHAR: os << t.cval;break;
	case Token::DBL: os << t.dval;break;
	case Token::STR: os << t.sval;break;
	case Token::SALES_DATA: os << t.sdval;break;
	}

	return os;
}

int main()
{
	Token t;
	t = 'c';
	t = 42;
	t = 3.14;
	t = "hello";
	t = Sales_data("0-201-70353-X", 4, 24.99);

	t = t;
	cout << t << endl;

	return 0;
}
