// 条款24：若所有参数皆需类型转换，请为此采用 non-member 函数
#ifndef __RULE24_H__
#define __RULE24_H__

#include <iostream>

extern void Rule24();

namespace rule24
{
	// 一个有理数类型
	class Rational {
	public:
		// 构造函数刻意不为 explicit ，从而允许 int-to-Rational 隐式转换
		Rational(int numberator = 0, int denominator = 1) : numberator_(numberator), denominator_(denominator) {}

		int numerator() const { return numberator_; }
		int denominator() const { return denominator_; }

		// 将乘法运算定义成 member ，但这样做适用性不强
		/*const Rational operator* (const Rational& rhs) const
		{
			return Rational(numberator_ * rhs.numberator_, denominator_ * rhs.denominator_);
		}*/

	private:
		int numberator_, denominator_;
	};

	// 应该将乘法操作定义成 non-member 函数
	inline const Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
	}

	inline std::ostream& operator<<(std::ostream &os, Rational &r)
	{
		os << r.numerator() << "/" << r.denominator();
		return os;
	}
}

#endif // __RULE24_H__