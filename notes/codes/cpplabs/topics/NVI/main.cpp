// NVI ，即 non-virtual interface ，其使用一个普通的 public 成员函数调用 private virtual 成员函数
// 比较有效地解决了拥有默认实参的调用问题：如果 private virtual 成员函数拥有默认实参，这个默认值属于静态绑定，这意味着派生类不可以修改这个默认实参，从而导致代码重复
// 参考 Effect C++ 条款 37

#include "Tiger.h"

int main()
{
    Tiger tiger;

    tiger.BattleCry(3);

    return 0;
}