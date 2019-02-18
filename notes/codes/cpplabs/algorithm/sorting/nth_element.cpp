/*
    void nth_element(first, nth, last);
    void nth_element(first, nth, last, comp);

    部分排序，使得 [first, nth) 的元素都小于等于 nth 后的元素。
    默认使用 operator< 比价元素，或可使用 comp

    排序后，[first, nth) 并没有一定是排序的。
*/

#include <vector>
#include <iostream>
#include <algorithm>

void Test1()
{
    std::vector<int> vec { 19, 1, 30, 21, 8, 14, 11 };

    // 使得前3个元素都大于后面的
    std::nth_element(vec.begin(), vec.begin() + 3, vec.end(), std::greater<int>());

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    Test1();

    return 0;
}