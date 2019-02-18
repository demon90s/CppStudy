/*
    void sort_heap(first, last);
    void sort_heap(first, last, comp);

    转换最大堆 [first, last) 为升序排序的范围，产生的范围不再拥有堆属性。
    默认采用 operator< 比较，也可以用可调用对象 comp 。
*/

#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> v {3, 6, 1, 29, 1, 22};

    std::cout << "initially, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    std::make_heap(v.begin(), v.end());
    std::cout << "after make_heap, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    std::sort_heap(v.begin(), v.end());
    std::cout << "after sort_heap, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    return 0;
}