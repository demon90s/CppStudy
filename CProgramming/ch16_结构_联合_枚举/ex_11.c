/*
    假设s具有下列结构（ point 是在练习5中声明的结构标记 ）：

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
    } s;

    请指出下列哪些语句是合法的，并且说明如何修改不合法的语句：
    (a) s.shape_kind = RECTANGLE;
    (b) s.center.x = 10;
    (c) s.length = 25;
    (d) s.u.rectangle.width = 8;
    (e) s.u.circle = 5;
    (f) s.u.radius = 5;
*/

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
} s;

int main(int argc, char const *argv[])
{
    /* a 合法 */
    s.shape_kind = RECTANGLE;

    /* b 合法 */
    s.center.x = 10;

    /* c 不合法，已修改 */
    s.u.rectangle.length = 25;

    /* d 合法 */
    s.u.rectangle.width = 8;

    /* e 不合法，已修改 */
    s.u.circle.radius = 5;

    /* f 不合法，已修改 */
    s.u.circle.radius = 5;

    return 0;
}
