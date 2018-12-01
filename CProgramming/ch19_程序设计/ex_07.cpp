/*
    给 Fraction 类添加重载运算符+, -, 和/。写出这些运算符的定义以及 print 函数和 reduce 函数的
    实现。
*/

#include <iostream>
#include <string>

class Fraction {
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
public:
    Fraction() : numberator(0), denominator(0) {}
    Fraction(int n, int d) : numberator(n), denominator(d) {}

    const char* get()
    {
        dec = std::to_string(numberator) + "/" + std::to_string(denominator);
        return dec.c_str();
    }

    void print()
    {
        printf("%d/%d\n", numberator, denominator);
    }
    void reduce()
    {
        int m, n, tmp;
        m = numberator;
        n = denominator;

        while (n != 0) {
            tmp = m;
            m = n;
            n = tmp % n;
        }

        numberator /= m;
        denominator /= m;
    }

private:
	int numberator;
	int denominator;
    std::string dec;
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    Fraction ret;
    ret.numberator = lhs.numberator * rhs.denominator + rhs.numberator * lhs.denominator;
    ret.denominator = lhs.denominator * rhs.denominator;
    ret.reduce();
    return ret;
}
Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    Fraction ret;
    ret.numberator = lhs.numberator * rhs.denominator - rhs.numberator * lhs.denominator;
    ret.denominator = lhs.denominator * rhs.denominator;
    ret.reduce();
    return ret;
}
Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    Fraction ret;
    ret.numberator = lhs.numberator * rhs.denominator;
    ret.denominator = lhs.denominator * rhs.numberator;
    ret.reduce();
    return ret;
}

int main(int argc, char const *argv[])
{
    Fraction f1(6, 8);
    f1.print();
    f1.reduce();
    printf("after reduce: ");
    f1.print();

    Fraction f2(2, 5);
    printf("%s + %s = %s\n", f1.get(), f2.get(), (f1 + f2).get());
    printf("%s - %s = %s\n", f1.get(), f2.get(), (f1 - f2).get());
    printf("%s / %s = %s\n", f1.get(), f2.get(), (f1 / f2).get());

    return 0;
}
