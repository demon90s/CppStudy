/*
    std::lexicographical_compare

    检查第一个范围[first1, last1)是否按字典序小于第二个范围[first2, last2)

    lexicographical_compare(first1, last1, first2, last2)
    用 operator< 比较元素

    lexicographical_compare(first1, last1, first2, last2, comp)
    用二元谓词比较元素
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> v1 {1, 2, 3, 4};
    std::vector<int> v2 {1, 2, 3, 4, 5};
    std::vector<int> v3 {1, 3};

    std::cout << "{1, 2, 3, 4} < {1, 2, 3, 4, 5} ? " << std::boolalpha <<
            std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;

    std::cout << "{1, 2, 3, 4} < {1, 3} ? " << std::boolalpha <<
            std::lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()) << std::endl;
}

int main(int argc, char const *argv[])
{
    Test1();
    
    return 0;
}
