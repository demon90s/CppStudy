/*
    #include <stdarg.h>
    void va_start(va_list ap, param n);
    T va_arg(va_list ap, T);
    void va_end(va_list ap);

    这些方法提供处理可变数量参数的能力。

    对于这样的调用 func(n, ...)
    可以使用 `va_list ap` 来代表 ... ，即可变参数列表。
    之后，使用 va_start(ap, n) 初始化 ap ， n 是 ... 前面那个形参名字。

    va_arg 将从 ap 中读取一个类型为T的数据并返回，然后 ap 的读取位置前进到下一个。

    va_end 将 ap 清扫。
*/

#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/*
    序列化内置类型到 buffer, buffer 的大小为 sz
    序列化格式由 format 和变长参数列表提供，其中
    i - int
    d - double
    s - C风格字符串

    成功返回序列化的字节长度，失败返回-1
*/
int serialize(char buffer[], size_t sz, const char *format, ...)
{
    const char *p;
    va_list ap;
    char *cur_pos = buffer;
    int ret = 0;

    va_start(ap, format);

    p = format;
    while (*p != '\0') {
        switch (*p++)
        {
            case 'i': {
                int v = va_arg(ap, int);
                if (cur_pos - buffer + sizeof(int) > sz) { ret = -1; goto end; }
                *(int*)cur_pos = v;
                cur_pos += sizeof(int);
            }
            break;

            case 'd': {
                double v = va_arg(ap, double);
                if (cur_pos - buffer + sizeof(double) > sz) { ret = -1; goto end; }
                *(double*)cur_pos = v;
                cur_pos += sizeof(double);
            }
            break;

            case 's': {
                const char* v = va_arg(ap, const char*);
                if (cur_pos - buffer + strlen(v) + 1 > sz) { ret = -1; goto end; }
                strcpy(cur_pos, v);
                cur_pos += strlen(v) + 1;
            }
            break;

            default: ret = -1; goto end;
        }
    }

end:
    va_end(ap);
    if (ret < 0) {
        return ret;
    }
    return cur_pos - buffer;
}

/*
    从 buffer 中反序列化内置类型的数据出来, buffer 的大小为 sz
    序列号化格式由 format 和变长参数列表提供，其中
    i - int
    d - double
    s - C风格字符串

    成功返回0，失败返回-1
*/
int unserialize(char buffer[], size_t sz, const char *format, ...)
{
    const char *p;
    va_list ap;
    char *cur_pos = buffer;
    int ret = 0;

    va_start(ap, format);

    p = format;
    while (*p != '\0') {
        switch (*p++)
        {
            case 'i': {
                int *v = va_arg(ap, int*);
                if (cur_pos - buffer + sizeof(int) > sz) { ret = -1; goto end; }
                *v = *(int*)cur_pos;
                cur_pos += sizeof(int);
            }
            break;

            case 'd': {
                double *v = va_arg(ap, double*);
                if (cur_pos - buffer + sizeof(double) > sz) { ret = -1; goto end; }
                *v = *(double*)cur_pos;
                cur_pos += sizeof(double);
            }
            break;

            case 's': {
                char* v = va_arg(ap, char*);
                if (strlen(cur_pos) == 0) { ret = -1; goto end; }
                if (cur_pos - buffer + strlen(cur_pos) + 1 > sz) { ret = -1; goto end; }
                strcpy(v, cur_pos);
                cur_pos += strlen(v) + 1;
            }
            break;

            default: ret = -1; goto end;
        }
    }

end:
    va_end(ap);
    return ret;
}

int main(int argc, char const *argv[])
{
    char buffer[18];
    int n;
    {
        if ((n = serialize(buffer, 18, "ids", 42, 3.14, "Hello")) > 0) {
            printf("serailize %d bytes success\n", n);
        }
        else {
            printf("serialize failed\n");
        }
    }

    {
        int i;
        double d;
        char s[32];
        if (unserialize(buffer, n, "ids", &i, &d, s) == 0) {
            printf("unserialize success, i[%d], d[%f], s[%s]\n", i, d, s);
        }
        else {
            printf("unserialize failed\n");
        }
    }
    
    return 0;
}
