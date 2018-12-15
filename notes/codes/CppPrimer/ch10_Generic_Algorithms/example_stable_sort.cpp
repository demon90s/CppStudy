// example: stable_sort（p345）
// 另见：http://zh.cppreference.com/w/cpp/algorithm/stable_sort

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Employee {
	Employee(int age, std::string name) : age(age), name(name) {}

	int age;
	std::string name; // 不参与比较
};

// 年龄小的放前面
bool operator<(const Employee &lhs, const Employee &rhs) {
	return lhs.age < rhs.age;
}

int main()
{
	std::vector<Employee> v = {
		Employee(108, "Zaphod"),
		Employee(32, "Brthur"),
		Employee(32, "Arthur"),
		Employee(32, "Crthur"),
		Employee(108, "Ford"),
	};

	// 保证相等元素的（原有）顺序
	std::stable_sort(v.begin(), v.end());

	for (const auto &e : v) {
		std::cout << e.age << ", " << e.name << "\n";
	}

	return 0;
}
