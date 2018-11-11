#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "token.h"

/*
    获取逆波兰表达式的值，输入#或EOF结束表达式：
    30 5 - 7 * #

    结果等于 (30 - 5) * 7 = 175
*/

int main()
{
    TokenType token_type;
    int n1, n2;
    int result;

    while (1)
    {
        token_type = next_token();
        if (token_type == TYPE_END)
        {
            break;
        }
        else if (token_type == TYPE_NUMBER)
        {
            stack_push(get_last_number());
        }
        else if (token_type == TYPE_OP)
        {
            n1 = stack_pop();
            n2 = stack_pop();
            switch(get_last_op())
            {
                case '+': result = n2 + n1;
                break;

                case '-': result = n2 - n1;
                break;

                case '*': result = n2 * n1;
                break;

                case '\\': result = n2 / n1;
                break;
            }
            stack_push(result);
        }
    }

    printf("result: %d\n", stack_pop());

    return 0;
}