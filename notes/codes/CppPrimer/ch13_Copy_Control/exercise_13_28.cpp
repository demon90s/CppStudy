// 练习13.28：给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。

// TreeNode采用行为像指针的设计，拷贝的对象共享底层数据
// BinStrTree阻止其拷贝

#include <iostream>
#include <string>

using namespace std;

class TreeNode {
public:
	TreeNode(const std::string &s) : value(s), count(0), left(nullptr), right(nullptr), use(new size_t(1)) { cout << "TreeNode(const std::string &s): " << s << endl;}

	~TreeNode()
	{
		cout << "~TreeNode()" << endl;

		if (--*use == 0)
		{
			delete use;
			if (left) delete left;
			if (right) delete right;

			cout << "~TreeNode() real delete" << endl;
		}
	}

	TreeNode(const TreeNode &node) : value(node.value), count(node.count), left(node.left), right(node.right), use(node.use)
	{
		++*use;

		cout << "TreeNode(const TreeNode &node): " << value << endl;
	}

	TreeNode& operator=(const TreeNode &node)
	{
		cout << "TreeNode& operator=(const TreeNode &node): " << node.value << endl;

		++*node.use;
		if (--*use == 0)
		{
			delete use;
			if (left) delete left;
			if (right) delete right;
		}

		value = node.value;
		count = node.count;
		left = node.left;
		right = node.right;
		return *this;
	}

private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;

	size_t *use;
};

class BinStrTree {
public:
	BinStrTree() : root(new TreeNode("root")) { cout << "BinStrTree()" << endl; }

	~BinStrTree() { cout << "~BinStrTree()" << endl; delete root; }

	BinStrTree(const BinStrTree&) = delete;
	BinStrTree& operator=(const BinStrTree&) = delete;

	TreeNode Root() const { return *root; }

private:
	TreeNode *root;
};

int main()
{
	BinStrTree tree;
	
	auto root = tree.Root();

	//BinStrTree tree2 = tree; // cant copy tree

	return 0;
}
