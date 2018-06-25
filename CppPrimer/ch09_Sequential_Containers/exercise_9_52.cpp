// 练习9.52：使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。
// 当你在一个左括号之后看到一个右括号，从stack中pop对象，直到遇到左括号，将
// 左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示一个
// 括号化的（子）表达式处理完毕，被其运算结果所替代。

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string expr = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
	char repl = '#';
	int seen = 0;

	stack<char> stk;
	for (auto c : expr) {
		stk.push(c);
		if (c == '(') ++seen;
		if (seen && c == ')') {
			while (stk.top() != '(')
				stk.pop();
			stk.pop();
			stk.push(repl);
			--seen;
		}
	}

	// test
	string output;
	while (!stk.empty()) {
		output.insert(output.begin(), stk.top());
		stk.pop();
	}
	cout << output << endl;

	return 0;
}
