/*
    std::mismatch
    返回来自两个范围：一个以[first1, last1)定义而另一个以[first2, last2)定义，的首个不匹配对。

    mismatch(first1, last1, first2)
    使用 operator== 比较元素。

    返回值：指向首两个不相等元素的迭代器的 std::pair 。若比较抵达 last1 或 last2 中首先发生者时未找到不匹配，则 pair
    保有尾迭代器和来自另一个范围的对应迭代器。
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> v1 {1, 2, 3, 4, 5};
    std::vector<int> v2 {1, 2, 3, 3, 5};

    auto diff_pair = std::mismatch(v1.begin(), v1.end(), v2.begin());
    if (diff_pair.first != v1.end() && diff_pair.second != v2.end()) {
        std::cout << "diff pos at v1: " << std::distance(v1.begin(), diff_pair.first) << std::endl;
    }
    else {
        std::cout << "no diff between v1 and v2" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Test1();
    return 0;
}
