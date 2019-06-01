/*
    编写一个程序，用来模拟称为“掷双骰”游戏。程序要通过随机选择1到6之间的两个数来“滚动”一对
    模拟的骰子。如果两个数的和是7或11，那么程序显示信息 player wins 。如果和为2、3或12，则
    显示 Player lose 。否则，程序要重复滚动骰子直到再一次达到原始和（Player wins）或者骰子
    合计为7（Player lose）为止。程序需要在每次模拟滚动后显示一下骰子的值。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    /* 开始，定义变量，设置随机种子 */
    int num1, num2, sum;
    srand(time(NULL));

    /* 接受一次输入，滚动一次骰子，并判断结果 */
    while (1) {
        printf("Press any key to start rolling ...");
        getchar();

        num1 = rand() % 6 + 1;
        num2 = rand() % 6 + 1;

        printf("numbers: {%d %d}\n", num1, num2);

        sum = num1 + num2;
        if (sum == 7 || sum == 11) {
            printf("Player win\n");
            return 0;
        }
        else if (sum == 2 || sum == 3 || sum == 12) {
            printf("Player lose\n");
            return 0;
        }
    }
    
    return 0;
}
