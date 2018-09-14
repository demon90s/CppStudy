// 条款21：必须返回对象时，别妄想返回其 reference
#ifndef __RULE21_H__
#define __RULE21_H__

extern void Rule21();

namespace rule21
{
	class Rational {
	public:
		Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}

	private:
		int n, d;

		friend const Rational operator* (const Rational& lhs, const Rational &rhs);
	};

	// 这里应该返回一个值，而不是 reference
	inline const Rational operator* (const Rational& lhs, const Rational &rhs)
	{
		return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	}
}

#endif // __RULE21_H__