/*
    下列结构用来存储图形屏幕上的对象信息。结构 point 用来存储屏幕上点的x轴和y轴坐标，结构
    rectangle 用来存储矩形的左上和右下坐标点。

    struct point { int x, y;};
    struct rectangle { struct point upper_left, lower_right; };

    编写函数，要求可以在 rectangle 型结构变量r上执行下列操作，且r作为实际参数传递。

    (a) 计算r的面积。
    (b) 计算r的中心，并且把此中心作为 point 型的值返回。
    (c) 移动r，方法是x单元按照X轴方向移动，y单元按照y轴移动，并且返回r修改后的内容。（x和y是函数额外的实际参数。）
    (d) 确定点p是否位于r内，返回 TRUE 或者 FALSE 。（p是具有 struct point 类型的额外的实际参数。）
*/

#include <stdio.h>

struct point
{
    int x, y;
};
struct rectangle
{
    struct point upper_left, lower_right;
};

/* a */
int GetArea(struct rectangle r)
{
    int h = r.lower_right.x - r.upper_left.x;
    int w = r.lower_right.y - r.upper_left.y;
    return h * w;
}

/* b */
struct point GetMidPoint(struct rectangle r)
{
    int mid_x = r.upper_left.x + (r.lower_right.x - r.upper_left.x) / 2;
    int mid_y = r.upper_left.y + (r.lower_right.y - r.upper_left.y) / 2;
    struct point mid_point = {mid_x, mid_y};
    return mid_point;
}

/* c */
struct rectangle move(struct rectangle r, int x, int y)
{
    r.lower_right.x += x;
    r.upper_left.x += x;

    r.lower_right.y += y;
    r.upper_left.y += y;

    return r;
}

/* d */
typedef enum
{
    TRUE,
    FALSE
} Bool;
Bool IsIn(struct rectangle r, struct point p)
{
    return p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
           p.y >= r.upper_left.y && p.y <= r.lower_right.y;
}

int main(int argc, char const *argv[])
{
    struct rectangle r = {{0, 0}, {6, 8}}; /* 以左上角为坐标轴原点 */

    printf("area: %d\n", GetArea(r));
    printf("mid point: (%d,%d)\n", GetMidPoint(r).x, GetMidPoint(r).y);

    r = move(r, -3, -4);
    printf("move (-3, -4): {(%d, %d), (%d, %d)}\n", r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);

    struct point p = {1, 1};
    printf("point(1, 1) is in rectangle? %s\n", IsIn(r, p) ? "yes" : "no");

    struct point p2 = {4, 1};
    printf("point(4, 1) is in rectangle? %s\n", IsIn(r, p2) ? "yes" : "no");

    return 0;
}
