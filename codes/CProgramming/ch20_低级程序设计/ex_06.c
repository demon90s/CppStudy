/*
    (a) 使用按位运算符编写如下函数：
        unsigned short int swap_byte(unsigned short int i);
        函数 swap_byte 的返回值是将i的两个字节调换后产生的结果。（在大多数计算机中，短整型数据占
        两个字节。）例如，假设i的值是0x1234(二进制形式为00010010 00110100)，那么 swap_byte
        的返回值应该为0x3412(二进制形式00110100 00010010)。编写一个程序来测试你的函数。程序
        以十六进制读入数，然后交换两个字节并显示出来：
        Enter a hexadecimal number: 1234
        Number with byte swapped:   3412
        提示：使用%hx转换来读入和输出十六进制数

    (b) 将 swap_byte 函数的函数体化简为一条语句。
*/

#include <stdio.h>

struct trans_field {
    unsigned short low:8;
    unsigned short high:8;
};

union trans {
    struct trans_field tf;
    unsigned short int i;
};

unsigned short int swap_byte(unsigned short int i)
{
    /* tricks for b, 复合语句也算一条语句 */
    {
        unsigned short tmp;

        union trans t;
        t.i = i;
        
        tmp = t.tf.low;
        t.tf.low = t.tf.high;
        t.tf.high = tmp;

        return t.i;
    }
}

int main(int argc, char const *argv[])
{
    unsigned short int i;

    printf("Enter a hexadecimal number: ");
    scanf("%hx", &i);
    printf("Number with byte swapped: %hx\n", swap_byte(i));

    return 0;
}
