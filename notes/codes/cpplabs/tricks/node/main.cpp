#include "Node.h"
#include <iostream>

int main()
{
    Node node;

    node.SetChar('a');
    std::cout << node.GetChar() << std::endl;

    node.SetString("hello world");
    std::cout << node.GetString() << std::endl;

    node.SetInt(42);
    std::cout << node.GetInt() << std::endl;

    return 0;
}