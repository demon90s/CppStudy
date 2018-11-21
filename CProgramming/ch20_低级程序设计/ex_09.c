/*
    当按照IEEE浮点标准存储浮点数时，一个 float 类型的值由一个符号位（最左边的位或最重要的位），
    8个指数位以及23个小数位依次组成。请设计一个32位的结构类型，包含与符号位、指数位和小数位
    相对应的位域成员。声明的位域类型为 unsigned int 。请参考你的用户手册来决定位域的顺序。
    警告：一些编译器会限制位域在16位以内，因此当你编译这个结构
*/

struct type_field {
    unsigned int d:23;      /* 小数位 */
    unsigned int e:8;       /* 指数位 */
    unsigned int s:1;       /* 符号位 */
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
