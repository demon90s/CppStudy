#include "Node.h"
#include <iostream>

void test1()
{
    Node node;

    node.SetChar('a');
    std::cout << node.GetChar() << std::endl;

    node.SetString("hello world");
    std::cout << node.GetString() << std::endl;

    node.SetInt(42);
    std::cout << node.GetInt() << std::endl;
}

void test2()
{
    Node node1, node2;

    node1.SetString("hello");
    node2.SetString("hello");

    std::cout << std::boolalpha << (node1 == node2) << std::endl;           // true

    node2.SetString("wowo");

    std::cout << std::boolalpha << (node1 == node2) << std::endl;           // false
}

int main()
{
    //test1();
    test2();

    return 0;
}