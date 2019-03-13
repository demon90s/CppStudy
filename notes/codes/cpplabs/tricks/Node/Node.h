#pragma once

// 一个可以存放多种类型的类, 采用 union 实现

#include <cstring>

enum class NodeType {
    Char,
    Short,
    Int,
    LongLong,
    String,
};

class Node {
    friend bool operator==(const Node&, const Node&);
    friend bool operator!=(const Node&, const Node&);
public:
    Node();
    ~Node();
    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

    NodeType GetType() const { return type_; }

    void SetChar(char c);
    char GetChar() const { return value_.c; }

    void SetShort(short s);
    short GetShort() const { return value_.s; }

    void SetInt(int i);
    int GetInt() const { return value_.i; }

    void SetLongLong(long long ll);
    long long GetLongLong() const { return value_.ll; }
    
    void SetString(const char *str);
    const char* GetString() const { return value_.str; }

private:
    void CheckDeleteString();

    NodeType type_;

    union {
        char c;
        short s;
        int i;
        long long ll;
        char *str;
    } value_;
};

inline bool operator==(const Node& lhs, const Node& rhs)
{
    switch (lhs.type_)
    {
    case NodeType::Char:
        return lhs.GetChar() == rhs.GetChar();

    case NodeType::Short:
        return lhs.GetShort() == rhs.GetShort();

    case NodeType::Int:
        return lhs.GetInt() == rhs.GetInt();

    case NodeType::LongLong:
        return lhs.GetLongLong() == rhs.GetLongLong();

    case NodeType::String:
        return strcmp(lhs.GetString(), rhs.GetString()) == 0;

    default:
        return false;
    }
}

inline bool operator!=(const Node& lhs, const Node& rhs)
{
    return !(lhs == rhs);
}