// 练习13.26：对上一题中描述的StrBlob类，编写你自己的版本。

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> il) :
			data(std::make_shared<std::vector<std::string>>(il)) {}

	StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) {}

	StrBlob& operator=(const StrBlob &sb)
	{
		data = std::make_shared<std::vector<std::string>>(*sb.data);
		return *this;
	}

	inline size_type size() const { return data->size(); }
	inline bool empty() const { return data->empty(); }

	// 添加和删除元素
	inline void push_back(const std::string &t) { data->push_back(t); }
	inline void pop_back();

	// 元素访问
	inline std::string& front();
	inline std::string& back();
	inline std::string& front() const;
	inline std::string& back() const;

	std::string& operator[](size_type i) { return (*data)[i]; } // 省略了check

private:
	std::shared_ptr<std::vector<std::string>> data;

	// 如果data[i]不合法，抛出一个异常
	inline void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
	// 如果vector为空，check会抛出一个异常
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

int main()
{
	using namespace std;

	StrBlob sb1;
	sb1.push_back("hi");
	cout << "sb1[0]: " << sb1[0] << endl;

	StrBlob sb2 = sb1;
	cout << "sb2[0]: " << sb2[0] << endl;
	
	sb2[0] = "wow";

	cout << "sb1[0]: " << sb1[0] << endl;
	cout << "sb2[0]: " << sb2[0] << endl;

	return 0;
}
