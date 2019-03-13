#include "Node.h"
#include <cstring>

Node::Node()
{
    type_ = NodeType::Char;
    value_.str = nullptr;
}

Node::~Node()
{
    this->CheckDeleteString();
}

void Node::CheckDeleteString()
{
    if (type_ == NodeType::String && value_.str != nullptr) {
        delete[] value_.str;
        value_.str = nullptr;
    }
}

void Node::SetChar(char c)
{
    this->CheckDeleteString();

    type_ = NodeType::Char;
    value_.c = c;
}

void Node::SetShort(short s)
{
    this->CheckDeleteString();

    type_ = NodeType::Short;
    value_.s = s;
}

void Node::SetInt(int i)
{
    this->CheckDeleteString();

    type_ = NodeType::Int;
    value_.i = i;
}

void Node::SetLongLong(long long ll)
{
    this->CheckDeleteString();

    type_ = NodeType::LongLong;
    value_.ll = ll;
}

void Node::SetString(const char *str)
{
    char *tmp = new char[strlen(str) + 1];
    strcpy(tmp, str);

    this->CheckDeleteString();

    type_ = NodeType::String;
    value_.str = tmp;
}