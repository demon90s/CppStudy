#ifndef STACK_H
#define STACK_H

#define IMPL_BY_ARR
/* #define IMPL_BY_LIST */

typedef int ValueType;

/* 使用数组实现的 stack 结构 */
#ifdef IMPL_BY_ARR
struct stack {
    int top;
    int size;
    ValueType *values;
};
#endif

/* 使用链表实现的 stack 结构 */
#ifdef IMPL_BY_LIST
struct node {
    ValueType value;
    struct node *next;
};

struct stack {
    struct node *header;
};
#endif

typedef struct stack Stack;

Stack* stack_init();
void stack_destroy(Stack *stack);
void stack_make_empty(Stack *stack);
int stack_is_empty(Stack *stack);
void stack_push(Stack *stack, ValueType v);
ValueType stack_pop(Stack *stack);

#endif // STACK_H