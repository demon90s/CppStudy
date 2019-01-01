#include <iostream>
#include <string>

class IntArr {
public:
	explicit IntArr(int cnt) : cnt_(cnt) 
	{ list_ = new int[10]{}; }

	~IntArr()
	{
		delete[] list_;
	}

	IntArr(const IntArr&) = delete;
	IntArr& operator=(const IntArr&) = delete;

	int& operator[](int i)
	{ return list_[i]; }

	int* begin() { return list_; }
	int* end() { return list_ + cnt_; }

private:
	int cnt_;
	int *list_;
};

int main()
{
	{
		IntArr int_arr(10);

		for (auto &i : int_arr) {
			i = 10;
		}

		for (auto i : int_arr) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	
	return 0;
}
