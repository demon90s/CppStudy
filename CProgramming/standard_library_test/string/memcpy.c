/*
    void* memcpy(void *des, const void *src, size_t num);
    从 src 中拷贝 num 个字节到 des 。
    返回 des 。
    为了避免 overflow ，需要保证 des 和 src 的空间都至少 num 个字节大小
    des 和 src 不能有重叠的部分，如果有，那么应该使用 memmove 函数。
*/

#include <stdio.h>
#include <string.h>

struct {
    char name[40];
    int age;
} person, person_copy;

int main(int argc, char const *argv[])
{
    char myname[] = "liudiwen";

    /* using memcpy to copy string */
    memcpy(person.name, myname, strlen(myname) + 1);
    person.age = 28;

    /* using memcpy to copy structure */
    memcpy(&person_copy, &person, sizeof(person));

    printf("person_copy: %s %d\n", person_copy.name, person_copy.age);
    
    return 0;
}
