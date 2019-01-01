// capacity和size（p318）

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec;
	// size应该为0，capacity的值依赖于具体实现
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;
	
	// 向ivec添加24个元素
	for (int i = 0; i < 24; ++i)
		ivec.push_back(i);

	// size应该为24，capacity应该大于等于24，具体值依赖于标准库实现
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;
	ivec.reserve(50);	// 将capacity至少设定为50，可能会更大
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;

	// 添加元素用光多余容量
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	// capacity应该未改变，size和capacity相等
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;

	// 如果再添加一个元素，vector不得不重新分配空间
	ivec.push_back(42);
	// size应该为51，capacity至少为51，具体值依赖于标准库实现
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;

	// 可以调用shrink_to_fit要求vector将超出当前大小的多余内存退回给系统
	ivec.shrink_to_fit();
	// size应该未改变，capacity的值依赖于具体实现
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;

	return 0;
}
