// 条款18：让接口容易被正确使用，不易被误用
#ifndef __RULE18_H__
#define __RULE18_H__

extern void Rule18();

namespace rule18
{
	// 这个类型的接口可能会被误用，籍由传入错误的参数， int 无法识别参数的实际类型
	class Date1 {
	public:
		Date1(int month, int day, int year) : month_(month), day_(day), year_(year) {}

	private:
		int month_, day_, year_;
	};

	// 使用类型系统
	struct Day {
		explicit Day(int d) : val(d) {}
		int	val;
	};

	struct Month {
	public:
		static Month Jan() { return Month(1); }	// 以函数替换对象，表现某个特定月份
		static Month Feb() { return Month(2); }
		//...
		static Month Dec() { return Month(12); }
	private:
		explicit Month(int m) : val(m) {}		// 阻止生成新的月份
		int val;
	};

	struct Year {
		explicit Year(int y) : val(y) {}
		int val;
	};

	class Date2 {
	public:
		Date2(const Month& m, const Day& d, const Year& y) : month_(m), day_(d), year_(y) {}

	private:
		Month month_;
		Day day_;
		Year year_;
	};
	
}

#endif // __RULE18_H__