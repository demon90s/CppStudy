/*
    std::equal
    两个范围相等，返回 true ，否则返回 false

    equal(first1, last1, first2)
    使用 operator== 比较元素

    equal(first1, last1, first2, binary_pred)
    使用二元谓词比较
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

void Test1()
{
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::list<int> lst {1, 2, 3, 4, 5, 6};

    bool is_equal = std::equal(vec.begin(), vec.end(), lst.begin());
    std::cout << (is_equal ? "equal" : "not equal") << std::endl;
}

int main(int argc, char const *argv[])
{
    Test1();
    return 0;
}
