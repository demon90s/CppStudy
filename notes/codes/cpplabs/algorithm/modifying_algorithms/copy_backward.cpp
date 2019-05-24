/*
    copy_backward(first, last, d_last)
    复制来自[first, last)所定义范围的元素，到终于d_last的范围。以逆序复制元素（首先复制末尾元素），但保持其相对顺序。
*/

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> from_vector;
    for (int i = 0; i < 10; i++) {
        from_vector.push_back(i);
    }

    std::vector<int> to_vector(15);

    std::copy_backward(from_vector.begin(), from_vector.end(), to_vector.end());

    std::cout << "to_vector contains:";
    for (auto i : to_vector)
        std::cout << " " << i;
    std::cout << std::endl;
    
    return 0;
}
