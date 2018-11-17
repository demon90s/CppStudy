#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node* add_to_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = list;
    return new_node;
}

struct node* search_list(struct node *list, int n)
{
    struct node *p;

    for (p = list; p != NULL; p = p->next) {
        if (p->value == n)
            return p;
    }
    return NULL;
}

struct node* delete_from_list(struct node *list, int n)
{
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
        cur != NULL && cur->value != n;
        prev = cur, cur = cur->next);

    if (cur == NULL)
        return list;            /* n was not found */

    if (prev == NULL)
        list = list->next;      /* n is in the first node */
    else
        prev->next = cur->next; /* n is in some other node */

    free(cur);
    return list;
}

struct node* delete_from_list_ex_07(struct node *list, int n)
{
    struct node *prev;

    for (prev = NULL;
        list != NULL && list->value != n;
        prev = list, list = list->next);

    if (list == NULL)
        return NULL;             /* n was not found */

    if (prev == NULL) {
        prev = list;
        list = list->next;      /* n is in the first node */
        free(prev);
        return list;
    }
    else {
        prev->next = list->next; /* n is in some other node */
        prev = list;
        free(prev);
        return NULL;
    }
}

void delete_from_list_ex_11(struct node **list, int n)
{
    struct node *cur, *prev;

    for (cur = (*list), prev = NULL;
        cur != NULL && cur->value != n;
        prev = cur, cur = cur->next);

    if (cur == NULL)
        return;                         /* n was not found */

    if (prev == NULL)
        (*list) = (*list)->next;        /* n is in the first node */
    else
        prev->next = cur->next;         /* n is in some other node */

    free(cur);
}

void destroy_list(struct node *list)
{
    struct node *tmp;
    while (list) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}