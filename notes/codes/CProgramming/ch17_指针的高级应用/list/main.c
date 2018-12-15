#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(struct node *list)
{
    for (; list != NULL; list = list->next) {
        printf("%d ", list->value);
    }
    printf("\n");
}

struct node* read_numbers()
{
    struct node *first = NULL;
    int n;

    printf("Enter a series of integers(0 to terminate): ");
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return first;

        first = add_to_list(first, n);
    }
}

void search(struct node *list)
{
    int n;
    struct node *node;

    printf("Enter number to search: ");
    scanf("%d", &n);

    node = search_list(list, n);
    if (node) {
        printf("Find node: %p\n", node);
    }
    else {
        printf("Can't find node\n");
    }
}

void delete(struct node **list)
{
    int n;
    struct node *node;

    printf("Enter number to delete: ");
    scanf("%d", &n);

    /* *list = delete_from_list(*list, n); */
    
    /*
    node = delete_from_list_ex_07(*list, n);
    if (node != NULL) {
        *list = node;
    }
    */

   delete_from_list_ex_11(list, n);
}

int main(int argc, char const *argv[])
{
    struct node *list = read_numbers();
    print_list(list);

    search(list);
    delete(&list);

    print_list(list);

    destroy_list(list);

    return 0;
}
