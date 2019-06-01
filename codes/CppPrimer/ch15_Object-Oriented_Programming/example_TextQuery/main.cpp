// example: 文本查询程序再探(p562)

#include <fstream>
#include <iostream>
#include <string>

#include "TextQuery.h"
#include "QueryResult.h"

#define DEFAULT_EXAMPLE
//#define TEST_EX15_37
//#define TEST_EX15_41

#ifdef TEST_EX15_37
#include "Query_ex15_37.h"
#endif

#ifdef TEST_EX15_41
#include "Query_ex15_41.h"
#endif

#ifdef DEFAULT_EXAMPLE
#include "Query.h"
#endif

using namespace std;

void runQueries(ifstream &infile)
{
	// infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile); // 保存文件并建立查询map

	// 与用户交互，提示用户输入要查询的单词，完成查询并打印结果
	while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		// 若遇到了文件尾或用户输入了q时循环终止
		if (!(cin >> s) || s == "q") break;

		// 指向查询并打印结果
		print(cout, tq.query(s)) << endl;
	}
}

void func1()
{
	ifstream infile("../../data/little_story.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return;
	}

	runQueries(infile);
}

// 练习15.36
void func2()
{
	Query q = (Query("fiery") & Query("bird")) | Query("wind");
	cout << q << endl;
}

// 练习15.39
void func3()
{
	Query q0 = Query("Daddy");
	Query q1 = ~Query("Alice");
	Query q2 = Query("hair") | Query("Alice");
	Query q3 = Query("hair") & Query("Alice");
	Query q4 = (Query("fiery") & Query("bird")) | Query("wind");

	ifstream infile("../../data/little_story.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return;
	}

	TextQuery tq(infile);

	print(cout, q0.eval(tq));
	print(cout, q1.eval(tq));
	print(cout, q2.eval(tq));
	print(cout, q3.eval(tq));
	print(cout, q4.eval(tq));
}

// 练习15.42（c）
void func4()
{
	Query q = ~Query("Alice");

	ifstream infile("../../data/little_story.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return;
	}

	TextQuery tq(infile);

	std::pair<size_t, size_t> line_range{6, 10};
	print(cout, q.eval(tq), &line_range);
}

int main()
{
	//func1();
	//func2();
	//func3();
	func4();

	return 0;
}
