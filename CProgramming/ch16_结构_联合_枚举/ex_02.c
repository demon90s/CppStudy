/*
    (a) 声明名为c1, c2和c3的结构变量，每个结构变量都拥有 double 型的成员 re 和im 。
    (b) 修改(a)中的声明，使c1的成员初始值为0.0和1.0，而c2的成员初始值为1.0和0.0。(c3无初始值。)
    (c) 编写名为 make_complex 的函数，此函数用来把两个实际参数（两个参数的类型都是 double 型）
        存储在 complex 型结构中，然后返回此结构。
    (d) 编写名为 add_complex 的函数，此函数用来把两个实际参数（都是 complex 型结构）的相应成员
        进行相加运算，然后返回结果（另一个 complex 型结构）。
*/

/* a */
/*
struct {
    double re, im;
} c1, c2, c3;
*/

/* b */
struct {
    double re, im;
} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

/* c */
typedef struct complex {
    double param1;
    double param2;
} complex;
complex make_complex(double p1, double p2)
{
    complex c = {p1, p2};
    return c;
}

/* d */
complex add_complex(complex c1, complex c2)
{
    complex c;
    c.param1 = c1.param1 + c2.param1;
    c.param2 = c1.param2 + c2.param2;
    return c;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
