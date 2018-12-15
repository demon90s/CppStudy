/*
    is_sorted

    检查范围中的元素是否不以降序排序。

    is_sorted(first, last)
    用 operator== 比较元素

    is_sorted(first, last, comp)
    用二元谓词比较元素
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec { 5, 4, 3, 2, 1 };

    std::cout << "is vec sorted: " << std::boolalpha << std::is_sorted(vec.begin(), vec.end()) << std::endl;

    std::sort(vec.begin(), vec.end());

    std::cout << "is vec sorted: " << std::boolalpha << std::is_sorted(vec.begin(), vec.end()) << std::endl;
}

int main(int argc, char const *argv[])
{
    Test1();
    return 0;
}
