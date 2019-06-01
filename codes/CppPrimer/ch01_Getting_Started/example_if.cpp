// example: if语句（p15）

#include <iostream>

// 统计输入中每个值连续出现了多少次
int main()
{
	// currVal是我们正在统计的数；我们将读入的新值存入val
	int currVal = 0, val = 0;

	if (std::cin >> currVal) {
		int cnt = 1;	// 保存正在处理的当前值的个数
		while (std::cin >> val) {	// 读取剩余的数
			if (val == currVal)		// 如果值相同，将cnt加1，否则打印前一个值的个数
				++cnt;
			else {
				std::cout << currVal << " occurs " << cnt << " times" << std::endl;
				currVal = val;	// 记住新值
				cnt = 1;		// 重置计算器
			}
		}

		// 记住打印文件最后一个值的个数
		std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	}

	return 0;
}
