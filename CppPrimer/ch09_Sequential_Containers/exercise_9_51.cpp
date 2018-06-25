// 练习9.51：设计一个类，它有三个unsigned成员，分别表示年、月、日。为其编写
// 构造函数，接受一个表示日期的string参数。你的构造函数应该能处理不同数据格式，
// 如January 1, 1990、1/1/1990、Jan 1 1990等。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
public:
	Date() = default;
	Date(const string &d);

	void Print()
	{
		cout << "year: " << year << endl;
		cout << "month: " << month << endl;
		cout << "day:" << day << endl;
	}

private:
	unsigned year = 0;
	unsigned month = 0;
	unsigned day = 0;
};

Date::Date(const string &d)
{
	static string numbers = "0123456789";
	static vector<string> months_long = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November",
		"December"
	};

	static vector<string> months_short = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov",
		"Dec"
	};

	// Januery 1, 1990
	if (d.find(",") != string::npos) {
		for (size_t i = 0; i < months_long.size(); ++i) {
			if (d.find(months_long[i]) != string::npos) {
				month = i + 1;
				break;
			}
		}
		auto day_pos = d.find_first_of(numbers);
		auto mark_pos = d.find(",");
		day = stoi(d.substr(day_pos, mark_pos - day_pos));
		year = stoi(d.substr(mark_pos + 1));
		
		return;
	}
	
	// 1/1/1990
	if (d.find("/") != string::npos)
	{
		auto first_mark_pos = d.find("/");
		day = stoi(d.substr(0, first_mark_pos));
		auto last_mark_pos = d.rfind("/");
		month = stoi(d.substr(first_mark_pos + 1, last_mark_pos - first_mark_pos - 1));
		year = stoi(d.substr(last_mark_pos + 1));

		return;
	}
	
	// Jan 1 1990
	{
		for (size_t i = 0; i < months_short.size(); ++i) {
			if (d.find(months_short[i]) != string::npos) {
				month = i + 1;
				break;
			}
		}

		auto first_mark_pos = d.find(" ");
		auto last_mark_pos = d.rfind(" ");
		day = stoi(d.substr(first_mark_pos + 1, last_mark_pos - first_mark_pos - 1));
		year = stoi(d.substr(last_mark_pos + 1));
	}
	
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cerr << "Please enter the date, example: \"January 1, 1990\"" << endl;
		return 1;
	}

	Date date(argv[1]);
	date.Print();

	return 0;
}
