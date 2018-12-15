#ifndef STACK_H
#define STACK_H

#define PUBLIC /* empty */
#define PRIVATE static

PUBLIC void stack_make_empty();
PUBLIC int stack_is_empty();
PUBLIC void stack_push();
PUBLIC int stack_pop();

#endif // STACK_H