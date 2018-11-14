/*
    假设 shape 是练习11中声明的结构标记。编写函数用来在 shape 型结构变量s上完成下列操作，并且s
    作为实际参数在函数间传递：

    (a) 计算s的面积。
    (b) 计算s的中心，返回 point 型的中心值。
    (c) 移动s，方法是x单元按照x轴方向移动，y单元按照y轴移动，并且返回s修改后的内容。（x和y是函数额外的实际参数。）
    (d) 确定点p是否位于s内，返回 TRUE 或者 FALSE 。（p是具有 struct point 类型的额外的实际参数。）
*/

#include <stdio.h>

#define PI 3.14

typedef enum { TRUE, FALSE } Bool;

enum { RECTANGLE, CIRCLE };

struct point {
    int x, y;
};

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int length, width;
        } rectangle;

        struct {
            int radius;
        } circle;
    } u;
};

typedef struct point Point;
typedef struct shape Shape;

/* a */
double GetArea(const Shape* shape);

/* b */
Point GetCenter(const Shape* shape)
{
    return shape->center;
}

/* c */
void Move(Shape* shape, int x, int y)
{
    shape->center.x += x;
    shape->center.y += y;
}

/* d */
Bool IsIn(const Shape* shape, Point p)
{
    if (shape->shape_kind == RECTANGLE) {
        Point upper_left, lower_right;
        upper_left.x = shape->center.x - shape->u.rectangle.length / 2;
        upper_left.y = shape->center.y - shape->u.rectangle.width / 2;
        lower_right.x = shape->center.x + shape->u.rectangle.length / 2;
        lower_right.y = shape->center.y + shape->u.rectangle.width / 2;

        return p.x >= upper_left.x && p.x <= lower_right.x &&
                p.y >= upper_left.y && p.y <= lower_right.y;
    }
    else {
        return (p.x - shape->center.x) * (p.x - shape->center.x) + (p.y - shape->center.y) * (p.y - shape->center.y) <= shape->u.circle.radius * shape->u.circle.radius;
    }
}

int main(int argc, char const *argv[])
{
    Point zero = {0, 0};

    Shape s;
    s.shape_kind = RECTANGLE;
    s.center.x = s.center.y = 0;
    s.u.rectangle.length = 6;
    s.u.rectangle.width = 8;
    /* Move(&s, 7, 7); */
    printf("Area of rectangle s: %g\n", GetArea(&s));
    printf("Is point(0, 0) in s: %s\n", IsIn(&s, zero) ? "yes" : "no");

    s.shape_kind = CIRCLE;
    s.u.circle.radius = 6;
    printf("Area of circle s: %g\n", GetArea(&s));
    printf("Is point(0, 0) in s: %s\n", IsIn(&s, zero) ? "yes" : "no");

    return 0;
}

double GetArea(const Shape* shape)
{
    if (shape->shape_kind == RECTANGLE) {
        return shape->u.rectangle.length * shape->u.rectangle.width;
    }
    else {
        return PI * shape->u.circle.radius * shape->u.circle.radius;
    }
}