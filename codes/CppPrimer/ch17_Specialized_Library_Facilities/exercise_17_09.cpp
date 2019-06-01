// 练习17.9：解释下列每个bitset对象所包含的位模式。

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
	bitset<64> bitvec(32); // 共64位，低位为100000，高位全为0
	cout << bitvec.to_string() << endl;

	bitset<32> bv(1010101);	// 共32位，低位为11110110100110110101，高位全为0，用于初始化bv的参数应当看成是10进制数 
	cout << bv.to_string() << endl;

	string bstr; cin >> bstr; bitset<8> bv2(bstr); // 共8位，根据bstr来初始化，总共可以使用8个字符，下标大的初始化低位，超出的被丢弃
	cout << bv2.to_string() << endl;

	return 0;
}
