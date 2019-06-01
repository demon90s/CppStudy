/*
    (a) 为枚举声明标记，此枚举的值表示一个星期的7天。
    (b) 用 typedef 定义(a)中枚举的名字。
*/

/*
    (a)
    enum { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
*/

typedef enum { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY } WEEKDAY;

int main(int argc, char const *argv[])
{
    return 0;
}
