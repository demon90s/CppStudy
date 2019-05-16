/*
    一种操作数组的安全方法
*/

#include <climits>
#include <cstring>

class Foo {
public:
    Foo() { memset(arr, 0, sizeof(arr)); }
    void SetValue(unsigned short index, int value) {
        // nerver out of bound
        arr[index] = value;
    }
    int GetValue(unsigned short index) const {
        // never out of bound
        return arr[index];
    }

    int& operator[](unsigned short index) {
        // never ot of bound
        return arr[index];
    }

private:
    static const int MAX_SIZE = (int)USHRT_MAX + 1;
    int arr[MAX_SIZE];
};

//----------------------------------------------------------------
#include <iostream>
int main()
{
    Foo foo;
    std::cout << foo[-1] << std::endl;        // ok, never out of bound

    foo[100] = 42;
    std::cout << foo[100] << std::endl;

    foo[-1] = 42;
    std::cout << foo[-1] << std::endl;

    return 0;
}