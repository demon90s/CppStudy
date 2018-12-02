/*
    #include <locale.h>
    struct lconv *localeconv(void);

    获得指向 struct lconv 类型静态对象的指针，它表示当前C本地环境的数值和货币格式化规则。

    例如：
    - currency_symbol - 区域货币符号
    - int_curr_symbol - 国际货币符号
*/

#include <locale.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "ja_JP.UTF8");

    struct lconv* lc = localeconv();
    printf("Japanese currency symbol: %s(%s)\n", lc->currency_symbol, lc->int_curr_symbol);

    return 0;
}