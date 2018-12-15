/*
    invent.c
    Maintains a parts database (array version)
*/

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part_pointer_pair {
    struct part* prev;
    struct part* cur;
};

struct part *inventory = NULL; /* point to first part */

int num_parts = 0;      /* number of parts currently stored */

struct part* find_part(int number);
struct part_pointer_pair find_part2(int number);

void insert(void);
void search(void);
void update(void);
void erase(void);
void print(void);
void dump(void);
void restore(void);

/*
    main: Prompts the user to enter an operator code,
        then calls a function to perform the requested
        action. Repeats until the user enters the
        command 'q'. Prints an error message if th user
        enters an illegal code.
*/
int main(int argc, char const *argv[])
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); /* skips to end of line */

        switch(code) {
            case 'i': insert(); break;
            case 's': search(); break;
            case 'u': update(); break;
            case 'e': erase(); break;
            case 'p': print(); break;
            case 'd': dump(); break;
            case 'r': restore(); break;
            case 'q': printf("bye\n"); return 0;
            default: printf("Illegal code\n"); break;
        }
        printf("\n");
    }

    return 0;
}

/*
    find_part: Looks up a part number in the inventory
            list. Returns the pointer if the part
            number is found; otherwise, return NULL.
*/
struct part* find_part(int number)
{
    struct part *p;
    for (p = inventory; p != NULL && number > p->number;
        p = p->next);
    
    if (p != NULL && number == p->number)
        return p;

    return NULL;
}

struct part_pointer_pair find_part2(int number)
{
    struct part *p, *prev = NULL;
    struct part_pointer_pair ppp = {NULL, NULL};

    for (p = inventory; p != NULL && number > p->number;
        prev = p, p = p->next);
    
    if (p != NULL && number == p->number) {
        ppp.prev = prev;
        ppp.cur = p;
    }

    return ppp;
}

/*
    insert: Prompts the user for information about a new
            part and then inserts the part into the
            inventory list; the list remains sorted by
            part number. Prints an error message and
            returns prematurely if the part already exists
            or space could not be allocated for the part.
*/
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
        cur != NULL && new_node->number > cur->number;
        prev = cur, cur = cur->next);

    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/*
    search: Prompts the user to enter a part number, then
            looks up the part in the database. If the part
            exists, prints the name and quantity on hand;
            if not, prints an error message.
*/
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else {
        printf("Part not found.\n");
    }
}

/*
    update: Prompts the user to enter a part number.
            Prints an error message if the part doesn't
            exist; otherwise, prompts the user to enter
            change in quantity on hand and updates the
            database.
*/
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
    else {
        printf("Part not found.\n");
    }
}

/*
    for ex_09
*/
void erase(void)
{
    int number;
    struct part *p;
    struct part_pointer_pair ppp;

    printf("Enter part number to delete: ");
    scanf("%d", &number);

    ppp = find_part2(number);
    if (ppp.cur != NULL) {
        if (ppp.prev != NULL) {
            ppp.prev->next = ppp.cur->next;
            free(ppp.cur);
        }
        else {
            /* erase header */
            free(ppp.cur);
            inventory = NULL;
        }
    }
    else {
        printf("Part not found.\n");
    }
}

/*
    print: Prints a listing of all parts in the database,
            showing the part number, part name, and
            quantity on hand. Parts are printed in the
            order in which they were entered into the
            database.
*/
void print(void)
{
    struct part* p;
    printf("Part number    Part Name          Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next) {
        printf("%7d     %-25s%11d\n", p->number, p->name, p->on_hand);
    }
}

void dump(void)
{
    char file_name[128];
    FILE *fp;
    struct part *p;

    if (inventory == NULL) {
        printf("no parts to save\n");
        return;
    }

    printf("Enter name of output file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "wb");
    if (!fp) {
        fprintf(stderr, "fopen failed\n");
        return;
    }

    for (p = inventory; p != NULL; p = p->next) {
        fwrite(p, sizeof(inventory[0]), 1, fp);
    }

    fclose(fp);
}

void restore(void)
{
    char file_name[128];
    FILE *fp;
    int count_read, i;
    struct part *p, *tmp;
    struct part part_tmp;

    printf("Enter name of input file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");
    if (!fp) {
        fprintf(stderr, "fopen failed\n");
        return;
    }

    /* 销毁现有的表 */
    for (p = inventory; p != NULL;) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    inventory = NULL;

    /* 从文件中读取 */
    while (fread(&part_tmp, sizeof(part_tmp), 1, fp) > 0) {
        tmp = malloc(sizeof(part_tmp));
        *tmp = part_tmp;
        if (inventory == NULL) {
            inventory = tmp;
            p = inventory;
        }
        else {
            p->next = tmp;
            p = p->next;
        }
    }
    
    fclose(fp);
}