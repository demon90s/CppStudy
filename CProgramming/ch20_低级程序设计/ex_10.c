/*
    请设计一个联合类型，使一个32位的值既可以看作是一个 float 型的值，也可以看作是练习9中定义
    的结构。写一个程序将1存储在结构的符号位，将128存储在指数位，0存储在小数位。然后按 float
    值的形式显示存储在联合中的值。（如果你的位域设置正确的话，结果应该是-2.0。）
*/

#include <stdio.h>

struct type_field {
    unsigned int d:23;      /* 小数位 */
    unsigned int e:8;       /* 指数位 */
    unsigned int s:1;       /* 符号位 */
};

union type {
    struct type_field tf;
    float f;
};

int main(int argc, char const *argv[])
{
    union type t;
    t.tf.s = 1;
    t.tf.e = 128;
    t.tf.d = 0;

    printf("%.1f\n", t.f);
    
    return 0;
}
